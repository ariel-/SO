/*
 * Cliente.h
 *
 *  Created on: 28 feb. 2019
 *      Author: utnso
 */

#ifndef TP0_H_
#define TP0_H_

#include<stdio.h>
#include<stdlib.h>
#include<commons/log.h>
#include<commons/string.h>
#include<commons/config.h>
#include<readline/readline.h>

#include "utils.h"

void iniciar_logger(void);
void leer_config(void);
void leer_consola(void);
void paquete(int);
void terminar_programa(int);

#endif /* TP0_H_ */
