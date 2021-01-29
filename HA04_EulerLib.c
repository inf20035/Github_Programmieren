#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "HA04_EulerLib.h"

#define NUMOFSTATES 2

void RHS_MSD(double* rhs, double* y) { // mass spring damper

    //The used values here are for the extra task (the smallest number possible in the 'Aperiodischer Grenzfall'(?) for d is 3 (all values needed: m = 1.0, c = 2.0, d = 3.0, x_0 = 1, v_0 = 0))

    double m = 1.0; // mass of object (original mass = 1.0)

    double c = 2.0; // feder constant (original constant = 5.0)

    double d = 3.0; // damper constant (original constant = 0.25)    

    double x = y[0]; // position

    double v = y[1]; // speed

    /*calc derivatives and store in rhs*/

    rhs[0] = v;
    rhs[1] = -((d / m) * v + (c / m) * x);

}

void eulerSettings_MSD(simHandle* handle) {

    /*num of states*/

    handle -> numOfStates = NUMOFSTATES; //handle an NUMOFSTATES übergeben

    

    /*right hand site*/

     handle -> f = RHS_MSD; //RHS Funktion an handle Funktion übergeben

    

    /*reserve storage for init state vec*/

    handle -> stateVecInit = ((double*) malloc(sizeof(double) * (handle -> numOfStates));

    

    /*get user defined Simtime*/

    printf("Simtime (in s): \n");

    scanf("%lf", &(handle -> simTime));

    

    /*get user defined StepSize*/

    printf("StepSize (in s): \n");

    scanf("%lf", &(handle -> stepSize));
  if (handle -> stepSize <= 0 || handle -> stepSize > 5)

    {

        printf("stepsize need to be between 0 and 5\n");

        printf("Simtime (in s): \n");

        scanf("%lf", &(handle -> stepSize));

    }

    /*get init state position*/

    printf("position(t = 0): \n");

    scanf("%lf", &(handle -> stateVecInit[0]));

    /*get init state speed*/

    printf("speed(t = 0): \n");

    scanf("%lf", &(handle -> stateVecInit[1]));

    /*reserve storage for states and derivatives*/

    handle -> stateVec = (double*) malloc(sizeof(double) * ((int) ceil((handle->simTime / handle->stepSize) * (handle->numOfStates + 1))))

    handle -> derivStateVec = (double*) malloc(sizeof(double) * ((int) ceil((handle->simTime / handle->stepSize)  * (handle->numOfStates + 1))));

    
    /*init states and derivatives with zero*/

    for(int i = 0; i < (int) ceil((handle -> simTime / handle -> stepSize) * (handle -> numOfStates)); i++) { //handle durchlaufen und alles auf 0 setzen

        handle -> stateVec[i] = 0.0;

        handle -> derivStateVec[i] = 0.0;

    }

}
    
void eulerForward(simHandle* handle) { // this is called only once

    int numOfStates = handle->numOfStates;

    int integratorSteps = (int) ceil(handle->simTime / handle->stepSize);
      /*write init states*/

    for(int i = 0; i < numOfStates; i++) {

        handle->stateVec[i] = handle->stateVecInit[i]; //write the init values to the real vector used in calculations

    }

    for(int i = 0; i < integratorSteps; i++) {

        /*get derivatives*/

        handle -> f(&(handle -> derivStateVec[i * numOfStates]), &(handle -> stateVec[i * numOfStates]));

        for(int j = 0; j < numOfStates; j++) {

        /*euler step*/

            handle->stateVec[numOfStates + (i * numOfStates + j)] = handle -> stateVec[i * numOfStates + j] + handle -> stepSize * handle -> derivStateVec[i * numOfStates + j];

        }

    }

}

void showResults_MSD(simHandle* handle) {

    /*print data to text file*/

    FILE* fp = fopen("simData.txt", "r");


    for(int i = 0; i < (int) ceil((handle->simTime / handle->stepSize)); i++) {

        fprintf(fp, "%lf %lf %lf\n", (i * (handle -> stepSize)), handle -> stateVec[i * 2], handle -> stateVec[i * 3 + 1]); 

    }

  /*call gnuplot*/
    FILE* gnuplotPipe = popen("gnuplot -persistent", "w");

}
