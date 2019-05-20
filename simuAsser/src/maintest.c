//testing code for simulating the mecanic response of a robot and export the data in .csv format so it is easy to plot through python

#include <stdio.h>      /* printf, scanf, NULL */
#include <stdlib.h>     /* calloc, exit, free */

#include "sencoder.h"
#include "csv.h"
#include "sphysique.h"
#include "PID.h"

int main(){

    //setup varibles
        //time
    int n=0;
    double d_time=0.01;
    double d_subtime=0.001;
    double total_time =5; //in seconds

    int maxIteration=(int)(total_time/d_time);
    int maxSubIteration=(int)(d_time/d_subtime);

        //position in cm
    int * xpos = calloc(maxIteration*maxSubIteration,sizeof(int)); //position x
    int * ypos = calloc(maxIteration*maxSubIteration,sizeof(int)); //position y
    int * opos = calloc(maxIteration*maxSubIteration,sizeof(int)); //angle
    xpos[0]=0;
    ypos[0]=0;
    opos[0]=0;

    double * voltage_l =calloc(maxIteration,sizeof(double)); //voltage left and right
    double * voltage_r =calloc(maxIteration,sizeof(double));
    voltage_l[0] =0;
    voltage_r[0] =0;

    int sum=0;
    int diff=0;

    int encoder_l =0 , encoder_r=0;
        //pid parameters
    PID_VALUE pid_sum;
    InitializationPid(pid_sum,10,0.1,0.1,0.1) //no ; ? ,else goal,kp,ki,kd

    PID_VALUE pid_diff;
    InitializationPid(pid_diff,0,0.1,0.1,0.1) //no ; ? ,else goal,kp,ki,kd

    //actualisation loop
    //variables

    int nDivided;
    //loop
    while(n < maxIteration){
        //setup var
        nDivided =0;
        //actualisation pid value
        FinalValueCalculation(pid_sum,d_time,sum)
        FinalValueCalculation(pid_diff,d_time,diff)

        voltage_l = (double)(pid_sum.current - pid_diff.current)/2; // /2 is optionnal?
        voltage_r = (double)(pid_sum.current + pid_diff.current)/2;
        //actualisation physics
        while(nDivided < maxSubIteration){

            //actualisation motors etc..

            //actualisation encoder and sensors

            //writing to csv

        }
        //actualisation encoder values , sum and diff

        //writing to csv

    }

    //free memory
    free(xpos);
    free(ypos);
}