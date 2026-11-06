#include <stdio.h>

#define F_ELEC 0.727
#define F_METRO 0.03
#define F_BUS 0.07
#define F_2W 0.04
#define F_CAR 0.17
#define F_DIESEL 2.68
#define F_WASTE 0.45

struct Department {
    char name[50];
    float electricity;
    float metro;
    float bus;
    float two_wheeler;
    float car;
    float diesel;
    float waste;
    float total_emission;
};

struct Department campus[50];
int dept_count = 0;

void calculate_and_suggest(int index) {
    float e_elec = campus[index].electricity * F_ELEC;
    float e_trans = (campus[index].metro * F_METRO) + (campus[index].bus * F_BUS) +
                    (campus[index].two_wheeler * F_2W) + (campus[index].car * F_CAR);
    float e_gen = campus[index].diesel * F_DIESEL;
    float e_waste = campus[index].waste * F_WASTE;

    campus[index].total_emission = e_elec + e_trans + e_gen + e_waste;

    printf("Total CO2 Emission for %s: %.2f kg\n", campus[index].name, campus[index].total_emission);

    if (e_elec > e_trans && e_elec > e_gen && e_elec > e_waste) {
        printf("Solution: Switch to LEDs, optimize ACs, or use solar panels.\n");
    } else if (e_trans > e_elec && e_trans > e_gen && e_trans > e_waste) {
        printf("Solution: Introduce shuttle buses and promote bicycles.\n");
    } else if (e_gen > e_elec && e_gen > e_trans && e_gen > e_waste) {
        printf("Solution: Replace diesel generators with solar battery systems.\n");
    } else {
        printf("Solution: Add more segregated bins at concentrated areas.\n");
    }
}

int main() {
    int choice;
    FILE *file;

    file = fopen("records.txt", "r");
    if (file != NULL) {
        while (fscanf(file, "%s %f %f %f %f %f %f %f %f",
                      campus[dept_count].name, &campus[dept_count].electricity,
                      &campus[dept_count].metro, &campus[dept_count].bus,
                      &campus[dept_count].two_wheeler, &campus[dept_count].car,
                      &campus[dept_count].diesel, &campus[dept_count].waste,
                      &campus[dept_count].total_emission) == 9) {
            dept_count++;
        }
        fclose(file);
    }

    do {
        printf("\n--- Campus Carbon Footprint Analyzer ---\n");
        printf("1. Add new department data\n");
        printf("2. View all records and solutions\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("\nEnter Department Name (no spaces): ");
            scanf("%s", campus[dept_count].name);

            do { printf("Electricity (kWh): "); scanf("%f", &campus[dept_count].electricity); } while(campus[dept_count].electricity < 0);
            do { printf("Metro (km): "); scanf("%f", &campus[dept_count].metro); } while(campus[dept_count].metro < 0);
            do { printf("Bus (km): "); scanf("%f", &campus[dept_count].bus); } while(campus[dept_count].bus < 0);
            do { printf("2-Wheeler (km): "); scanf("%f", &campus[dept_count].two_wheeler); } while(campus[dept_count].two_wheeler < 0);
            do { printf("Car (km): "); scanf("%f", &campus[dept_count].car); } while(campus[dept_count].car < 0);
            do { printf("Diesel (L): "); scanf("%f", &campus[dept_count].diesel); } while(campus[dept_count].diesel < 0);
            do { printf("Waste (kg): "); scanf("%f", &campus[dept_count].waste); } while(campus[dept_count].waste < 0);

            calculate_and_suggest(dept_count);
            dept_count++;

            file = fopen("records.txt", "w");
            if (file != NULL) {
                for (int i = 0; i < dept_count; i++) {
                    fprintf(file, "%s %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f\n",
                            campus[i].name, campus[i].electricity, campus[i].metro,
                            campus[i].bus, campus[i].two_wheeler, campus[i].car,
                            campus[i].diesel, campus[i].waste, campus[i].total_emission);
                }
                fclose(file);
            }
        } else if (choice == 2) {
            for (int i = 0; i < dept_count; i++) {
                printf("\n--- %s ---\n", campus[i].name);
                calculate_and_suggest(i);
            }
        }

    } while (choice != 3);

    printf("Exiting program. Data is saved safely.\n");
    return 0;
}
