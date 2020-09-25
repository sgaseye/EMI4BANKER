#include<stdio.h>
#include<math.h>
#include<conio.h>
main(){
    int loan_amt,interest1,interest3,emi,i,j,k,l,n,temp,time4emi,foreclosure;

    printf("Enter Loan Amount:");
    scanf("%d",&loan_amt);

    printf("Enter Interest On Loan Amount:");
    scanf("%d",&interest1);

    int SI=(loan_amt*interest1)/100;
    printf("Simple Interest on Loan Amount: %d \n",SI);

    int Total_amt=loan_amt+SI;
    printf("Total Amount = Loan Amount + Simple Interest: %d \n",Total_amt);


    printf("Enter No. Of Installments:");
    scanf("%d",&emi);

    double monthly_emi= Total_amt/emi;
    printf("Installments you are going to pay each month: %lf \n", monthly_emi);


    //printf("Months after which you want your emi to have interest when you dont pay:");
    //scanf("%d",&time4emi);

    double interest2;
    printf("Enter Interest for Installments when not paid on time:");
    scanf("%lf",&interest2);

    printf("Enter foreclosure month no.:");
    scanf("%d", &foreclosure);

    printf("There are banks which do not charge interest from first month onwards.\nThese banks can start charging interest when you don't pay emi for some month.\nIt may be 2-3 months or anything \nThis depends on no. of installments and foreclosure period");
    printf("Month from when bank start charging Interest when you don't pay EMI:");
    scanf("%d", &n);

    double sum=0;
    double amount;
    printf("Let see how much money you will have to pay in foreclosure years!\n\n");
    printf("first entry is %lf on which bank will put no interest and remaining\n ",monthly_emi);
    printf("%4s%21s\n", "EMI", "Interest per EMI");

    for(i = 1; i <= foreclosure-n; i++){
        amount = monthly_emi * pow((1.0 + interest2/100), i);
        sum+= amount;
        printf("%4d%21.2f\n", i, amount);

        // i hereby denoted as year or month in our case
    }
    double sum2=sum+(n*monthly_emi);
    printf("the total amount to be paid for forclosure time:%lf \n",sum2);

    //float compoundInterestillforeclose=(monthly_emi*(pow((1+(interest2/(100*foreclosure))),(pow(foreclosure,2)))));
    //printf("Compound Interest is %f \n",compoundInterestillforeclose);

/*   for(i=0;i<emi;i++){
        while(i<foreclosure && i>n){
            float SI2=(monthly_emi*interest1)/100;

        }


    }*/

    if(n>foreclosure){
        printf("Bank will start charging interest on EMI after foreclosure since you give month that is beyond foreclosure period\n");
        printf("Therefore Interest will be charged on left-out EMIs\n");
        printf("Now we will calculate how bank will charge on left out EMIs\ni.e. EMI which were left to be interested after foreclosure period\n");
        int leftout= emi-n;
        int rest_amt=monthly_emi*leftout;
        printf("So, this much amount is left from foreclosure: %d \nAnd this will be interested differently \n therefore enter the interest for left-out EMIs:", rest_amt);
        scanf("%d", &interest3);

        int SI2=(rest_amt*interest3)/100;
        printf("Simple Interest on Rest EMI: %d \n",SI2);

        int Total_amt2= rest_amt+SI2;
        printf("Total Amount to be paid for Rest EMIs: %d \n", Total_amt2);

        double Complete_Sum=Total_amt2+sum2;
        printf("Complete money you will pay after foreclosure time : %lf \n", Complete_Sum );

    }


    else{
        printf("Now we will calculate how bank will charge on left out EMIs i.e.\nEMI which are not under foreclosure ");
        int leftout= emi-foreclosure;
        int rest_amt=monthly_emi*leftout;
        printf("So, this much amount is left from foreclosure: %d \nAnd this will be interested differently \n therefore enter the interest for leftout EMIs:", rest_amt);
        scanf("%d", &interest3);

        int SI2=(rest_amt*interest3)/100;
        printf("Simple Interest on Rest EMI: %d \n",SI2);

        int Total_amt2= rest_amt+SI2;
        printf("Total Amount to be paid for Rest EMIs: %d \n", Total_amt2);

        double Complete_Sum=Total_amt2+sum2;
        printf("Complete money you will pay after foreclosure time: %lf \n", Complete_Sum );
    }


}
