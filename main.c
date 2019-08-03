#include <stdio.h>
#include <string.h>

//prot�tipos
void calculaArgamassa();
void calculaAco();
void calculaConcretoObra();
void calculaConcretoUsinado();
void calculaTijolos();

int main() {

	int material;

	while (1){

		printf("\n\nEscolha qual material deseja calcular a quantidade: \n\n");
		printf("1 - Argamassa\n");
		printf("2 - Armacoes de Aco\n");
		printf("3 - Concreto de Obra\n");
		printf("4 - Concreto Usinado\n");
		printf("5 - Tijolos e Blocos\n");
		printf("0 - Sair do programa\n");

		scanf("%d", &material);

		switch (material)
		{
		case 0:
			return 0;
			break;
		case 1:
			calculaArgamassa();
			break;
		case 2:
			calculaAco();
			break;
		case 3:
			calculaConcretoObra();
			break;
		case 4:
			calculaConcretoUsinado();
			break;
		case 5:
			calculaTijolos();
			break;
		default:
			printf("Opção invalida");
			break;
		}
	}
}

void calculaArgamassa(){
	int tipo;
	float largura, comprimento, espessura, volume;
	float rendimentoCimento, rendimentoAreia, rendimentoCal;
	float cimento, areia, cal;

	printf("Escolha a finalidade da argamassa: \n");
	printf("1 - Contrapiso\n");
	printf("2 - Assentamento de ceramica\n");
	printf("3 - Assentamento de Bloco\n");
	printf("4 - Reboco\n");
	printf("0 - Voltar\n");

	scanf("%d", &tipo);

	printf("\ninforme as medidas de largura, comprimento e espessura (em metros)\n");
	printf("largura: ");
	scanf("%f", &largura);
	printf("\ncomprimento: ");
	scanf("%f", &comprimento);
	printf("\nespessura: ");
	scanf("%f", &espessura);

	volume = largura * comprimento * espessura;
	printf("O volume de argamassa e : %f\n metros cubicos", volume);

	switch (tipo)
	{
	case 0:
		return;
	case 1:
		printf("Os materiais usados sao cimento e areia, nas proporcoes 1:12\n");
		rendimentoCimento = 5;
		rendimentoAreia = 1.08;
		cimento = rendimentoCimento * volume;
		areia = rendimentoAreia * volume;
		printf("A quandidade de material necessaria e: \n");
		printf("Cimento: %f sacos de 50kg\n", cimento);
		printf("Areia: %f metros cubicos\n", areia);
		break;
	case 2:
		printf("Os materiais usados sao cimento, cal e areia nas proporcoes 1:4:16\n");
		rendimentoCimento = 3.65;
		rendimentoAreia = 1.4;
		rendimentoCal = 9;
		cimento = rendimentoCimento * volume;
		areia = rendimentoAreia * volume;
		cal = rendimentoCal * volume;
		printf("A quandidade de material necessaria e: \n");
		printf("Cimento: %f sacos de 50kg\n", cimento);
		printf("Areia: %f metros cubicos\n", areia);
		printf("Cal: %f sacos de 20kg\n", cal);
		break;
	case 3:
		printf("Os materiais usados sao cimento, cal e areia nas proporcoes 1:1:12\n");
		rendimentoCimento = 4.8;
		rendimentoAreia = 1.2;
		rendimentoCal = 2.95;
		cimento = rendimentoCimento * volume;
		areia = rendimentoAreia * volume;
		cal = rendimentoCal * volume;
		printf("A quandidade de material necessaria e: \n");
		printf("Cimento: %f sacos de 50kg\n", cimento);
		printf("Areia: %f metros cubicos\n", areia);
		printf("Cal: %f sacos de 20kg\n", cal);
		break;
	case 4:
		printf("Os materiais usados sao cimento, cal e areia nas proporcoes 1:4:18\n");
		rendimentoCimento = 3.3;
		rendimentoAreia = 1.1;
		rendimentoCal = 7.8;
		cimento = rendimentoCimento * volume;
		areia = rendimentoAreia * volume;
		cal = rendimentoCal * volume;
		printf("A quandidade de material necessaria e: \n");
		printf("Cimento: %f sacos de 50kg\n", cimento);
		printf("Areia: %f metros cubicos\n", areia);
		printf("Cal: %f sacos de 20kg\n", cal);
		break;
	default:
		printf("Opção invalida");
	}
}

void calculaAco() {

	int qntColunas;
	float altura, qntBarras, metragemLinear, metragemLinearTotal;
	float comprimento, largura, espacamento, metragemLinearEstribo, qntEstriboColuna, qntEstriboTotal, metragemLinearTotalEstribu;

	printf("O calculo do aco necessario e divido em duas etapas, primeiro se calcula a quantidade que sera ");
	printf("gasto com a metragem linear da coluna, em seguida se calcula a quantidade que sera gasta com os estribus ");
	printf("que est�o presentes nas colunas\n\n");
	printf("Para calcular a metragem linear da coluna informe a altura da coluna e a quantidade de barras\n");
	printf("Informe a altura da coluna: ");
	scanf("%f", &altura);
	printf("Informe a quantidade de barras da coluna: ");
	scanf("%f", &qntBarras);

	metragemLinear = altura * qntBarras;

	//printf("A quantidade de aco gasto por culuna sera: %f\n", metragemLinear);

	printf("Informe a quantidade de colunas: ");
	scanf("%d", &qntColunas);

	metragemLinearTotal = qntColunas * metragemLinear;

	printf("Agora sera calculada a metragem dos estribos\n");
	printf("Informe a largura da coluna: ");
	scanf("%f", &largura);
	printf("Informe o comprimento da coluna: ");
	scanf("%f", &comprimento);
	printf("Informe o espacamento: ");
	scanf("%f", &espacamento);

	metragemLinearEstribo = 2 * comprimento + 2 * largura + 0.20;
	qntEstriboColuna = altura / espacamento;
	
	qntEstriboTotal = qntEstriboColuna * qntColunas;
	metragemLinearTotalEstribu = metragemLinearEstribo * qntEstriboTotal;

	printf("Serao necessarias %f barras de aco de 12 metros para levantamento\n", (qntColunas*metragemLinear/12.0));
	printf("Serao necesssarias %f barras de aco de 12 metros para os estribos\n", (metragemLinearTotalEstribu / 12.0));


}

void calculaConcretoObra() {

	int tipo;
	float largura, comprimento, altura, volume;
	float cimento, areia, pedra, agua;

	printf("O concreto e feito com os materiais: cimento, areia, pedra e agua. A proporcao entre eles muda"
	 " de acordo com a finalidade do concreto.\n");

	printf("Escolha a finalidade do concreto: \n");
	printf("1 - Laje\n");
	printf("2 - Fundação (colunas, sapatas, vigas)\n");
	printf("3 - Contrapiso ou calçada\n");
	printf("0 - Voltar\n");

	scanf("%d", &tipo);


	printf("informe as dimensoes para se calcular a quantidade necessaria: \n");

	printf("Informe a largura: ");
	scanf("%f", &largura);
	printf("Informe o comprimento: ");
	scanf("%f", &comprimento);
	printf("Informe a altura: ");
	scanf("%f", &altura);

	volume = largura * comprimento * altura;

	switch (tipo)
	{
	case 1:
		printf("A proporcao dos materiais para o concreto de laje e de 1:1,5:2 sendo cimento, areia e pedra respectivamente, a agua e "
		"medida em função do volume de concreto, sendo 189 litros por metro cubico.\n");
		cimento = 7.7 * volume;
		areia = 0.524 * volume;
		pedra = 0.818 * volume;
		agua = 189 * volume;

		printf("Quantidade necessárias: \n");
		printf("Cimento: %f.2 sacos de 50kg\n", cimento);
		printf("Areia: %f.2 metros cubicos\n", areia);
		printf("Pedra: %f.2 metros cubicos\n", pedra);
		printf("Agua: %f.2 litros\n", agua);
		break;
	case 2:
		break;
	case 3:
		break;	
	default:
		printf("opcao invalida");
		break;
	}
	


}

void calculaConcretoUsinado() {

	float largura, comprimento, altura, volume;// volumeTotal;

	printf("O concreto usinado e vendido por metro cubico, sendo necessario apenas calcular o volume a ser usado\n");
	
	printf("Informe a largura: ");
	scanf("%f", &largura);
	printf("Informe o comprimento: ");
	scanf("%f", &comprimento);
	printf("Informe a altura: ");
	scanf("%f", &altura);

	volume = largura * comprimento * altura;
	//volumeTotal += volume;

	printf("Quantidade de concreto necessaria: %f ", volume);
	
}

void calculaTijolos(){

}











