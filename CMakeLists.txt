cmake_minimum_required(VERSION 3.14)
project(Definitivo C)

set(CMAKE_C_STANDARD 99)

add_executable(Definitivo main.c Hospede.h Operacaohospede.h Operacaohospede.c Helper.h Codigos.h Helper.c Hotel.h Hotel.c OperacaoHotel.h Fornecedores.h OperacaoFornecedores.c OperacaoFornecedores.h OperacaoAcomodacoes.c OperacaoOperadores.c Operador.h OperacaoOperadores.h OperacaoAcomodacoes.h Acomodacoes.h OperacaoCategoriaAcomodacoes.h OperacaoCategoriaAcomodacoes.c CategoriaAcomodacoes.h Produto.h OperacaoProdutos.c OperacaoProdutos.h Reserva.h operacaoReserva.c operacaoReserva.h)