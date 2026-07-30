#include <stdio.h>
#include <string.h>

/* =========================================================
   PHARMACY MANAGEMENT SYSTEM
   FINAL MAXIMUM EXTENDED VERSION
   ========================================================= */

/* =========================================================
   PROJECT DESCRIPTION
   This project is created using C language
   It demonstrates use of:
   - Structures
   - File Handling
   - Functions
   - String Manipulation
   ========================================================= */

/* =========================================================
   PURPOSE OF PROJECT
   This system helps user to:
   Identify disease
   Suggest medicine
   Provide shop details
   Provide dosage details
   Provide shop address
   ========================================================= */

/* =========================================================
   NOTE TO USER
   This system is for educational purpose only
   Always consult a doctor for real treatment
   ========================================================= */

/* =========================================================
   STRUCTURE DEFINITION
   ========================================================= */

struct Disease {
    char symptom[50];
    char medicine[50];
    char shop[50];
    char dosage[50];
    char address[100];
};

/* =========================================================
   FUNCTION: LOWERCASE CONVERSION
   ========================================================= */

void toLowerCase(char str[]) {
    int i;
    for(i = 0; str[i] != '\0'; i++) {
        if(str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + 32;
        }
    }
}

/* =========================================================
   FUNCTION: INTRO DISPLAY
   ========================================================= */

void intro() {

    printf("\n====================================================\n");
    printf("          PHARMACY MANAGEMENT SYSTEM\n");
    printf("====================================================\n");

    printf("\nWelcome to Smart Healthcare Assistant\n");

    printf("\n--------------------------------------------\n");
    printf("System Services Available\n");
    printf("Disease identification\n");
    printf("Medicine recommendation\n");
    printf("Shop and address information\n");
    printf("Dosage instructions\n");
    printf("--------------------------------------------\n");

    printf("\n--------------------------------------------\n");
    printf("User Guidelines\n");
    printf("Enter input carefully\n");
    printf("Avoid spaces in entries\n");
    printf("Use menu options properly\n");
    printf("--------------------------------------------\n");

    printf("\n--------------------------------------------\n");
    printf("Health Awareness\n");
    printf("Eat nutritious food\n");
    printf("Stay hydrated\n");
    printf("Exercise regularly\n");
    printf("--------------------------------------------\n");

    printf("\nStay Healthy Stay Safe\n");

    printf("\n====================================================\n");
}

/* =========================================================
   FUNCTION: LOAD DATA FROM FILE
   ========================================================= */

void loadData(struct Disease d[], int *count) {

    FILE *fp;
    char line[300];

    fp = fopen("pharmacy_data.txt", "r");

    if(fp == NULL) {
        printf("\nFile not found\n");
        printf("Please create pharmacy_data.txt file\n");
        return;
    }

    *count = 0;

    while(fgets(line, sizeof(line), fp) != NULL) {

        sscanf(line, "%s %s %s %s %s",
               d[*count].symptom,
               d[*count].medicine,
               d[*count].shop,
               d[*count].dosage,
               d[*count].address);

        (*count)++;
    }

    fclose(fp);

    printf("\n--------------------------------------------\n");
    printf("Data loaded successfully\n");
    printf("System ready\n");
    printf("--------------------------------------------\n");
}

/* =========================================================
   FUNCTION: SHOW ALL RECORDS
   ========================================================= */

void showAll(struct Disease d[], int count) {

    int i;

    printf("\n====================================================\n");
    printf("                ALL RECORDS\n");
    printf("====================================================\n");

    if(count == 0) {
        printf("\nNo records available\n");
        return;
    }

    for(i = 0; i < count; i++) {

        printf("\n--------------------------------------------\n");
        printf("Record Number : %d\n", i+1);
        printf("Symptom       : %s\n", d[i].symptom);
        printf("Medicine      : %s\n", d[i].medicine);
        printf("Shop          : %s\n", d[i].shop);
        printf("Dosage        : %s\n", d[i].dosage);
        printf("Address       : %s\n", d[i].address);
        printf("--------------------------------------------\n");
    }

    printf("\n====================================================\n");
    printf("All records displayed\n");
    printf("====================================================\n");
}

/* =========================================================
   FUNCTION: SEARCH RECORD
   ========================================================= */

void search(struct Disease d[], int count, char name[]) {

    char input[50];
    int i, found = 0;

    printf("\n--------------------------------------------\n");
    printf("SEARCH MODULE\n");
    printf("--------------------------------------------\n");

    printf("\nEnter your symptom: ");
    scanf("%s", input);

    FILE *fp;
    fp = fopen("user_history.txt", "a");

    if(fp != NULL) {
        fprintf(fp, "%s searched %s\n", name, input);
        fclose(fp);
    }

    printf("\nSearching database...\n");

    for(i = 0; i < count; i++) {

        char temp1[50], temp2[50];

        strcpy(temp1, input);
        strcpy(temp2, d[i].symptom);

        toLowerCase(temp1);
        toLowerCase(temp2);

        if(strcmp(temp1, temp2) == 0) {

            printf("\n********************************************\n");
            printf("              MATCH FOUND\n");
            printf("********************************************\n");

            printf("Symptom  : %s\n", d[i].symptom);
            printf("Medicine : %s\n", d[i].medicine);
            printf("Shop     : %s\n", d[i].shop);
            printf("Dosage   : %s\n", d[i].dosage);
            printf("Address  : %s\n", d[i].address);

            printf("********************************************\n");

            found = 1;
        }
    }

    if(found == 0) {
        printf("\nNo matching record found\n");
    }
}

/* =========================================================
   FUNCTION: ADD RECORD
   ========================================================= */

void addRecord() {

    FILE *fp;
    char symptom[50], medicine[50], shop[50], dosage[50], address[100];

    fp = fopen("pharmacy_data.txt", "a");

    printf("\n--------------------------------------------\n");
    printf("ADD RECORD MODULE\n");
    printf("--------------------------------------------\n");

    printf("\nEnter symptom: ");
    scanf("%s", symptom);

    printf("Enter medicine: ");
    scanf("%s", medicine);

    printf("Enter shop: ");
    scanf("%s", shop);

    printf("Enter dosage: ");
    scanf("%s", dosage);

    printf("Enter address: ");
    scanf("%s", address);

    fprintf(fp, "%s %s %s %s %s\n",
            symptom, medicine, shop, dosage, address);

    fclose(fp);

    printf("\nRecord added successfully\n");
}

/* =========================================================
   FUNCTION: MENU DISPLAY
   ========================================================= */

void menu() {

    printf("\n====================================================\n");
    printf("                    MAIN MENU\n");
    printf("====================================================\n");

    printf("1. Show All Data\n");
    printf("2. Search Disease\n");
    printf("3. Add Record\n");
    printf("4. Exit\n");

    printf("====================================================\n");
}

/* =========================================================
   MAIN FUNCTION
   ========================================================= */

int main() {

    struct Disease d[200];
    int count = 0, choice;
    char name[50];

    intro();

    printf("\nEnter your name: ");
    scanf("%s", name);

    printf("\n--------------------------------------------\n");
    printf("Welcome %s\n", name);
    printf("System initialized\n");
    printf("--------------------------------------------\n");

    loadData(d, &count);

    do {

        menu();

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        if(choice == 1) {
            showAll(d, count);
        }

        else if(choice == 2) {
            search(d, count, name);
        }

        else if(choice == 3) {
            addRecord();
            loadData(d, &count);
        }

        else if(choice == 4) {
            printf("\nThank you %s\n", name);
        }

        else {
            printf("\nInvalid choice\n");
        }

    } while(choice != 4);

    return 0;
}
