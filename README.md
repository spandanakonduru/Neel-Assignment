# Neel-Assignment

#include<stdio.h>
#include<string.h>


struct Bank
{
    char name[25];
    int acc_no;
    int pin;
    int balance;
};

struct Bank cust[2];

void cash_withdraw(int i){
    int amt;
    int op;
    printf("Enter the amount of cash you wish to withdraw: \n1.500\n2.1000\n3.5000\n4.10000");
    scanf("%d",&op);
    switch(op){
        case 1: amt=500;break;
        case 2: amt=1000;break;
        case 3: amt=5000;break;
        case 4: amt=10000;break;
    }
    if(amt>cust[i].balance){
        printf("\nInsufficent funds");
        printf("\nPlease enter an amount:");
        scanf("%d",&amt);
    }
    else
    {
        printf("You have withdrawn %d",amt);
        cust[i].balance = cust[i].balance - amt;
        printf("Your current balance is: %d",cust[i].balance);
    }
    
}

void balance_enquiry(int i){

    printf("\nYour balance is : %d",cust[i].balance);

}

void change_pin(int i){
    
    int new_pin;
    printf("\nEnter your new 4 digit pin: ");
    scanf("%d",&new_pin);

    cust[i].pin = new_pin;
    printf("\nYour pin has been changed");
}


void atm(int i){
    int option=1;
    while(option){
        int op;
        printf("\nEnter your option: \n1.Cash Withdrawal\n2.Balance Enquiry\n3. Pin Change\nEnter 0 to exit");
        scanf("%d",&op);
        switch(op){
            case 1: cash_withdraw(i); break;
            case 2: balance_enquiry(i); break;
            case 3: change_pin(i); break;
            case 0: atm_accept();
        }
    }
}


void atm_accept(){
    printf("Welcome to the ATM, please enter your account number: ");
    int acc_no;
    scanf("%d",&acc_no);
    int i=0;
    for(i=0;i<10;i++){
        if(cust[i].acc_no==acc_no){
            printf("Hello %s please enter your pin: \n",cust[i].name);
            int pin;
            scanf("%d",&pin);
            if (pin == cust[i].pin)
            {
                atm(i);
            }
        }
    else continue;
    }


}

void main(){
    

    int i=0;
    for(i=0;i<2;i++){
        printf("Enter the account number, name, balance and pin of %d customer",i);
        scanf("%d",&cust[i].acc_no);
        scanf("%s",cust[i].name);
        scanf("%d",&cust[i].balance);
        scanf("%d", &cust[i].pin);
    }


    //ATM MACHINE CODE
    
    atm_accept();

    int flag=0;
    printf("\nContinue? 1-Yes, 0-No");
    scanf("%d",&flag);

    if(flag==1)
        atm_accept();

}
