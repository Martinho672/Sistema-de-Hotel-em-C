#include <stdio.h>
#include "Codigos.h"

int RetornaCodigo(int opc, Codigo *codigo) {

    switch (opc) {
        case 0://hospede

            codigo->codigoHospede++;
            //gravaarquivo codigos
            return codigo->codigoHospede;
            break;

    }
}