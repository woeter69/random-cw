#!/bin/bash

PASS=0
FAIL=0

check() {
    local label="$1"
    local expected="$2"
    local got="$3"
    if [ "$got" = "$expected" ]; then
        echo "  ✅ PASS: $label"
        PASS=$((PASS+1))
    else
        echo "  ❌ FAIL: $label"
        echo "       expected: $expected"
        echo "       got:      $got"
        FAIL=$((FAIL+1))
    fi
}

########################################
echo ""
echo "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
echo "  FCFS TESTS"
echo "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"

# TC1: Single process (AT=0, BT=5)
# CT=5 TAT=5 WT=0
out=$(printf "1\n0\n5\n" | ./fcfs)
wt=$(echo "$out" | grep "Waiting Time" | awk '{print $NF}')
tat=$(echo "$out" | grep "Turn Around Time" | awk '{print $NF}')
ct=$(echo "$out" | grep "Completion Time" | awk '{print $NF}')
avg_tat=$(echo "$out" | grep "Average TAT" | awk '{print $NF}')
avg_wt=$(echo "$out" | grep "Average WT" | awk '{print $NF}')
echo "TC1: Single process AT=0 BT=5"
check "CT=5"      "5"   "$ct"
check "TAT=5"     "5"   "$tat"
check "WT=0"      "0"   "$wt"
check "Avg TAT=5" "5"   "$avg_tat"
check "Avg WT=0"  "0"   "$avg_wt"

# TC2: All same AT=0 (3 procs: BT 4,3,2)
# After FCFS sort by AT (all 0), order preserved: P1 BT4, P2 BT3, P3 BT2
# CT: 4, 7, 9 | TAT: 4,7,9 | WT: 0,4,7
out=$(printf "3\n0\n4\n0\n3\n0\n2\n" | ./fcfs)
wts=$(echo "$out" | grep "Waiting Time" | awk '{print $NF}' | tr '\n' ' ' | xargs)
tats=$(echo "$out" | grep "Turn Around Time" | awk '{print $NF}' | tr '\n' ' ' | xargs)
avg_tat=$(echo "$out" | grep "Average TAT" | awk '{print $NF}')
avg_wt=$(echo "$out" | grep "Average WT" | awk '{print $NF}')
echo "TC2: 3 procs all AT=0, BT=4,3,2"
check "WTs: 0 4 7"       "0 4 7"     "$wts"
check "TATs: 4 7 9"      "4 7 9"     "$tats"
check "Avg TAT=6.66667"  "6.66667"   "$avg_tat"
check "Avg WT=3.66667"   "3.66667"   "$avg_wt"

# TC3: Processes arrive out of order (P1:AT=5 BT=3, P2:AT=0 BT=2)
# Sorted by AT: P2(AT=0,BT=2) first, P1(AT=5,BT=3)
# CT: P2=2, P1=5+3=8 | TAT: P2=2, P1=3 | WT: P2=0, P1=0
out=$(printf "2\n5\n3\n0\n2\n" | ./fcfs)
# Output order after sort: P2 first, then P1
lines_wt=$(echo "$out" | grep "Waiting Time" | awk '{print $NF}')
wt1=$(echo "$lines_wt" | sed -n '1p')
wt2=$(echo "$lines_wt" | sed -n '2p')
echo "TC3: Out-of-order arrival (P1:AT5 BT3, P2:AT0 BT2)"
check "P2 WT=0 (runs first)"   "0"  "$wt1"
check "P1 WT=0 (CPU idle 2-5)" "0"  "$wt2"

# TC4: CPU idle gap (P1:AT=0 BT=1, P2:AT=10 BT=2)
# CT: P1=1, P2=12 | TAT: P1=1, P2=2 | WT: P1=0, P2=0
out=$(printf "2\n0\n1\n10\n2\n" | ./fcfs)
wts=$(echo "$out" | grep "Waiting Time" | awk '{print $NF}' | tr '\n' ' ' | xargs)
tats=$(echo "$out" | grep "Turn Around Time" | awk '{print $NF}' | tr '\n' ' ' | xargs)
echo "TC4: CPU idle gap (P1 AT0 BT1, P2 AT10 BT2)"
check "WTs: 0 0"    "0 0"  "$wts"
check "TATs: 1 2"   "1 2"  "$tats"

########################################
echo ""
echo "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
echo "  SJF TESTS"
echo "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"

# TC1: Single process AT=0 BT=5
out=$(printf "1\n0\n5\n" | ./sjf)
wt=$(echo "$out" | grep "Waiting Time" | awk '{print $NF}')
tat=$(echo "$out" | grep "Turn Around Time" | awk '{print $NF}')
echo "TC1: Single process AT=0 BT=5"
check "TAT=5" "5" "$tat"
check "WT=0"  "0" "$wt"

# TC2: Classic SJF (P1:AT=0,BT=8  P2:AT=1,BT=4  P3:AT=2,BT=9  P4:AT=3,BT=5)
# At t=0: only P1 avail, runs. CT1=8
# At t=8: P2(BT4), P3(BT9), P4(BT5) avail. SJF picks P2(BT4). CT2=12
# At t=12: P3(9),P4(5). Picks P4(5). CT4=17
# At t=17: P3(9). CT3=26
# TAT: P1=8, P2=11, P3=24, P4=14 | WT: P1=0, P2=7, P3=15, P4=9
out=$(printf "4\n0\n8\n1\n4\n2\n9\n3\n5\n" | ./sjf)
wts=$(echo "$out" | grep "Waiting Time" | awk '{print $NF}' | tr '\n' ' ' | xargs)
tats=$(echo "$out" | grep "Turn Around Time" | awk '{print $NF}' | tr '\n' ' ' | xargs)
avg_tat=$(echo "$out" | grep "Average TAT" | awk '{print $NF}')
avg_wt=$(echo "$out" | grep "Average WT" | awk '{print $NF}')
echo "TC2: Classic 4-process SJF"
check "WTs: 0 7 15 9"           "0 7 15 9"      "$wts"
check "TATs: 8 11 24 14"        "8 11 24 14"    "$tats"
check "Avg TAT=14.25"           "14.25"         "$avg_tat"
check "Avg WT=7.75"             "7.75"          "$avg_wt"

# TC3: Tie-break (same BT, earlier AT wins)
# P1:AT=0,BT=4  P2:AT=0,BT=4
# Both arrive at 0, same BT — SJF picks earlier AT (both=0, picks first by array order)
# P1 runs first: CT=4,TAT=4,WT=0 | P2: CT=8,TAT=8,WT=4
out=$(printf "2\n0\n4\n0\n4\n" | ./sjf)
wts=$(echo "$out" | grep "Waiting Time" | awk '{print $NF}' | tr '\n' ' ' | xargs)
echo "TC3: Tie-break same BT same AT"
check "WTs: 0 4" "0 4" "$wts"

# TC4: CPU idle then burst
# P1:AT=10,BT=3 -> CT=13 TAT=3 WT=0
out=$(printf "1\n10\n3\n" | ./sjf)
wt=$(echo "$out" | grep "Waiting Time" | awk '{print $NF}')
tat=$(echo "$out" | grep "Turn Around Time" | awk '{print $NF}')
echo "TC4: CPU idle until AT=10"
check "TAT=3" "3" "$tat"
check "WT=0"  "0" "$wt"

########################################
echo ""
echo "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
echo "  ROUND ROBIN TESTS"
echo "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"

# TC1: Single process AT=0 BT=5 Quantum=2
# Runs: 0-2 (rt=3), 2-4 (rt=1), 4-5 done. CT=5 TAT=5 WT=0
out=$(printf "1\n0\n5\n2\n" | ./rr)
wt=$(echo "$out" | grep "Waiting Time" | awk '{print $NF}')
tat=$(echo "$out" | grep "Turn Around Time" | awk '{print $NF}')
ct=$(echo "$out" | grep "Current Time" | awk '{print $NF}')
echo "TC1: Single process AT=0 BT=5 Q=2"
check "CT=5"  "5" "$ct"
check "TAT=5" "5" "$tat"
check "WT=0"  "0" "$wt"

# TC2: BT exactly equal to quantum
# P1:AT=0,BT=4 Q=4 -> CT=4 TAT=4 WT=0
out=$(printf "1\n0\n4\n4\n" | ./rr)
wt=$(echo "$out" | grep "Waiting Time" | awk '{print $NF}')
tat=$(echo "$out" | grep "Turn Around Time" | awk '{print $NF}')
echo "TC2: BT exactly = Quantum"
check "TAT=4" "4" "$tat"
check "WT=0"  "0" "$wt"

# TC3: 2 processes AT=0 BT=4,4 Q=2
# t=0: Q[0,1]. Run P1(2): t=2. Add new arrivals (none). Re-enqueue P1. Q=[1,0]
# t=2: Run P2(2): t=4. Re-enqueue P2. Q=[0,1]
# t=4: Run P1(2): t=6. P1 done. CT1=6 TAT1=6 WT1=2
# t=6: Run P2(2): t=8. P2 done. CT2=8 TAT2=8 WT2=4
out=$(printf "2\n0\n4\n0\n4\n2\n" | ./rr)
wts=$(echo "$out" | grep "Waiting Time" | awk '{print $NF}' | tr '\n' ' ' | xargs)
tats=$(echo "$out" | grep "Turn Around Time" | awk '{print $NF}' | tr '\n' ' ' | xargs)
echo "TC3: 2 procs AT=0 BT=4,4 Q=2"
check "WTs: 2 4"    "2 4"  "$wts"
check "TATs: 6 8"   "6 8"  "$tats"

# TC4: Quantum=1 all same AT (P1:BT=3,P2:BT=2 AT=0)
# t=0: Q[0,1]. Run P1(1):rt=2,t=1. Enqueue P1. Q=[1,0]
# t=1: Run P2(1):rt=1,t=2. Enqueue P2. Q=[0,1]
# t=2: Run P1(1):rt=1,t=3. Enqueue P1. Q=[1,0]
# t=3: Run P2(1):rt=0,t=4. P2 done. CT2=4 TAT2=4 WT2=2
# t=4: Run P1(1):rt=0,t=5. P1 done. CT1=5 TAT1=5 WT1=2
out=$(printf "2\n0\n3\n0\n2\n1\n" | ./rr)
wts=$(echo "$out" | grep "Waiting Time" | awk '{print $NF}' | tr '\n' ' ' | xargs)
tats=$(echo "$out" | grep "Turn Around Time" | awk '{print $NF}' | tr '\n' ' ' | xargs)
echo "TC4: Q=1 P1:BT3 P2:BT2 AT=0"
check "WTs: 2 2"    "2 2"  "$wts"
check "TATs: 5 4"   "5 4"  "$tats"

########################################
echo ""
echo "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
echo "  PAGE REPLACEMENT TESTS"
echo "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"

# TC1: Classic ref string 7,0,1,2,0,3,0,4,2,3,0,3,2 capacity=3
# Standard FIFO answer = 9 faults, LRU=8, (LIFO and MRU vary)
out=$(printf "13\n7\n0\n1\n2\n0\n3\n0\n4\n2\n3\n0\n3\n2\n3\n" | ./page_replacement)
fifo=$(echo "$out" | grep "FIFO" | awk '{print $NF}')
lru=$(echo "$out" | grep "LRU" | awk '{print $NF}')
echo "TC1: Classic ref string (13 pages, cap=3)"
check "FIFO faults=9" "9" "$fifo"
check "LRU faults=8"  "8" "$lru"

# TC2: All pages fit in cache (no replacements after initial load)
# ref: 1,2,3 cap=3  -> 3 faults (all initial), then 0 more
out=$(printf "3\n1\n2\n3\n3\n" | ./page_replacement)
fifo=$(echo "$out" | grep "FIFO" | awk '{print $NF}')
lifo=$(echo "$out" | grep "LIFO" | awk '{print $NF}')
lru=$(echo "$out" | grep "LRU" | awk '{print $NF}')
mru=$(echo "$out" | grep "MRU" | awk '{print $NF}')
echo "TC2: All distinct pages fit in cache (ref=1,2,3 cap=3)"
check "FIFO=3" "3" "$fifo"
check "LIFO=3" "3" "$lifo"
check "LRU=3"  "3" "$lru"
check "MRU=3"  "3" "$mru"

# TC3: All same page (capacity=1)
# ref: 5,5,5,5,5 cap=1 -> 1 fault (loaded once, then all hits)
out=$(printf "5\n5\n5\n5\n5\n5\n1\n" | ./page_replacement)
fifo=$(echo "$out" | grep "FIFO" | awk '{print $NF}')
lifo=$(echo "$out" | grep "LIFO" | awk '{print $NF}')
lru=$(echo "$out" | grep "LRU" | awk '{print $NF}')
mru=$(echo "$out" | grep "MRU" | awk '{print $NF}')
echo "TC3: All same page (ref=5,5,5,5,5 cap=1)"
check "FIFO=1" "1" "$fifo"
check "LIFO=1" "1" "$lifo"
check "LRU=1"  "1" "$lru"
check "MRU=1"  "1" "$mru"

# TC4: Capacity=1, alternating pages (worst case for FIFO/LRU/MRU)
# ref: 1,2,1,2,1 cap=1 -> 5 faults (every access is a fault)
out=$(printf "5\n1\n2\n1\n2\n1\n1\n" | ./page_replacement)
fifo=$(echo "$out" | grep "FIFO" | awk '{print $NF}')
lru=$(echo "$out" | grep "LRU" | awk '{print $NF}')
echo "TC4: Capacity=1 alternating 1,2 (all faults)"
check "FIFO=5" "5" "$fifo"
check "LRU=5"  "5" "$lru"

# TC5: LRU known result — ref 1,2,3,4,1,2,5,1,2,3,4,5 cap=4
# Standard LRU faults = 8
out=$(printf "12\n1\n2\n3\n4\n1\n2\n5\n1\n2\n3\n4\n5\n4\n" | ./page_replacement)
lru=$(echo "$out" | grep "LRU" | awk '{print $NF}')
fifo=$(echo "$out" | grep "FIFO" | awk '{print $NF}')
echo "TC5: Belady string (ref=1,2,3,4,1,2,5,1,2,3,4,5 cap=4)"
check "LRU=8"  "8"  "$lru"
check "FIFO=8" "8"  "$fifo"

########################################
echo ""
echo "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
echo "  RESULTS SUMMARY"
echo "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
echo "  Passed: $PASS"
echo "  Failed: $FAIL"
echo "  Total:  $((PASS+FAIL))"
