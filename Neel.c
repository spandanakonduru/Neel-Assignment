#include<stdio.h>
#include<string.h>

int n;


struct Bank
{
    char name[25];
    int acc_no;
    int pin;
    int balance;
};


void cash_withdraw(int i,struct Bank** cust){
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
        printf("Insufficent funds");
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

void balance_enquiry(int i,struct Bank** cust){

    printf("Your balance is : %d",cust[i].balance);

}

void change_pin(int i,struct Bank** cust){
    
    int new_pin;
    printf("Enter your new 4 digit pin: ");
    scanf("%d",&new_pin);

    cust[i].pin = new_pin;
    printf("Your pin has been changed");
}


void atm(int i, struct Bank **cust){
    int option=1;
    while(option){
        int op;
        printf("Enter your option: \n1.Cash Withdrawal\n2.Balance Enquiry\n3. Pin Change\n Enter 0 to exit");
        scanf("%d",&op);
        switch(op){
            case 1: cash_withdraw(i, &cust); break;
            case 2: balance_enquiry(i, &cust); break;
            case 3: pin_change(i, &cust); break;
            case 0: option=0; 
        }
    }
}


void atm_accept(struct Bank *cust){
    printf("Welcome to the ATM, please enter your account number: ");
    int acc_no;
    scanf("%d",&acc_no);
    int i=0;
    for(i=0;i<n;i++){
        if(cust[i].acc_no==acc_no){
            print("Hello %s please enter your pin: \n",cust[i].name);
            int pin;
            scanf("%d",&pin);
            if (pin == cust[i].pin)
            {
                atm(i, &cust);
            }
        }
    else continue;
    }


}

void main(){
    
    printf("Enter the number of Customers: \n");
    scanf("%d",&n);

    struct Bank cust[n];


    int i=0;
    for(i=0;i<n;i++){
        printf("Enter the account number, name, balance and pin of %d customer",i);
        scanf("%d",&cust[i].acc_no);
        scanf("%s",cust[i].name);
        scanf("%d",&cust[i].balance);
        scanf("%d", &cust[i].pin);
    }


    //ATM MACHINE CODE
    
    atm_accept(&cust);

    int flag=0;
    printf("Continue? 1-Yes, 0-No");
    scanf("%d",&flag);

    if(flag==1)
        atm_accept(&cust);
    

}
