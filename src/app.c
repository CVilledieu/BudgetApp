#include <stdlib.h>


typedef struct Transaction {
    int id;
    float amount;
    char *date; // Format: YYYY-MM-DD
    char *description;
} Transaction;


typedef struct Budget{
    float current_balance;
    float total_income;
    float total_expenses;
    int id;
    char *name;
    Transaction *transactions;
} Budget;


Budget budget_create(){
    Budget budget;
    budget.current_balance = 0.0f;
    budget.total_income = 0.0f;
    budget.total_expenses = 0.0f;
    budget.id = 0;
    budget.transactions = NULL; 
    return budget;
}

void budget_get(Budget b, int id){

}