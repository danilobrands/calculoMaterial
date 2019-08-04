#include <stdio.h>
#include <stdlib.h>
//#include <string.h>

//prototipos
void calculaArgamassa();
void calculaAco();
void calculaConcretoObra();
void calculaConcretoUsinado();
void calculaTijolos();

int main() {

	system("color 70");

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
	if(tipo == 0)
		return;

	printf("\ninforme as medidas de largura, comprimento e espessura (em metros)\n");
	printf("largura: ");
	scanf("%f", &largura);
	printf("\ncomprimento: ");
	scanf("%f", &comprimento);
	printf("\nespessura: ");
	scanf("%f", &espessura);

	volume = largura * comprimento * espessura;
	printf("O volume de argamassa e : %.2f\n metros cubicos", volume);

	switch (tipo)
	{
	case 0:
		break;
	case 1:
		printf("Os materiais usados sao cimento e areia, nas proporcoes 1:12\n");
		rendimentoCimento = 5;
		rendimentoAreia = 1.08;
		cimento = rendimentoCimento * volume;
		areia = rendimentoAreia * volume;
		printf("A quandidade de material necessaria e: \n");
		printf("Cimento: %.2f sacos de 50kg\n", cimento);
		printf("Areia: %.2f metros cubicos\n", areia);
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
		printf("Cimento: %.2f sacos de 50kg\n", cimento);
		printf("Areia: %.2f metros cubicos\n", areia);
		printf("Cal: %.2f sacos de 20kg\n", cal);
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
		printf("Cimento: %.2f sacos de 50kg\n", cimento);
		printf("Areia: %.2f metros cubicos\n", areia);
		printf("Cal: %.2f sacos de 20kg\n", cal);
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
		printf("Cimento: %.2f sacos de 50kg\n", cimento);
		printf("Areia: %.2f metros cubicos\n", areia);
		printf("Cal: %.2f sacos de 20kg\n", cal);
		break;
	default:
		printf("Opção invalida");
	}
}

void calculaAco() {

	int qntColunas;
	float altura, qntBarras, metragemLinear, metragemLinearTotal;
	float comprimento, largura, espacamento, metragemLinearEstribo, qntEstriboColuna, qntEstriboTotal, metragemLinearTotalEstribu;

	printf("\nO calculo do aco necessario e divido em duas etapas, primeiro se calcula a quantidade que sera ");
	printf("gasto com a metragem linear da coluna, em seguida se calcula a quantidade que sera gasta com os estribus ");
	printf("que estao presentes nas colunas\n\n");
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

	printf("\nSerao necessarias %.2f barras de aco de 12 metros para levantamento\n", (qntColunas*metragemLinear/12.0));
	printf("Serao necesssarias %.2f barras de aco de 12 metros para os estribos\n", (metragemLinearTotalEstribu / 12.0));


}

void calculaConcretoObra() {

	int tipo;
	float largura, comprimento, altura, volume;
	float cimento, areia, pedra, agua;

	printf("\nO concreto e feito com os materiais: cimento, areia, pedra e agua. A proporcao entre eles muda"
	 " de acordo com a finalidade do concreto.\n");

	printf("Escolha a finalidade do concreto: \n");
	printf("1 - Laje\n");
	printf("2 - Fundacao (colunas, sapatas, vigas)\n");
	printf("3 - Contrapiso ou calcada\n");
	printf("0 - Voltar\n");

	printf("Escolha uma opcao: ");
	scanf("%d", &tipo);


	printf("informe as dimensoes para se calcular a quantidade necessaria: \n");

	printf("Informe a espessura: ");
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
		"medida em funcao do volume de concreto, sendo 189 litros por metro cubico.\n");
		cimento = 7.7 * volume;
		areia = 0.524 * volume;
		pedra = 0.818 * volume;
		agua = 189 * volume;

		printf("\nQuantidade necessárias: \n");
		printf("Cimento: %.2f sacos de 50kg\n", cimento);
		printf("Areia: %.2f metros cubicos\n", areia);
		printf("Pedra: %.2f metros cubicos\n", pedra);
		printf("Agua: %.2f litros\n", agua);
		break;
	case 2:
		printf("A proporcao dos materiais para o concreto de fundação e de 1:2:3 sendo cimento, areia e pedra respectivamente, a agua e "
			"medida em funcao do volume de concreto, sendo 210 litros por metro cubico.\n");
		cimento = 6.9 * volume;
		areia = 0.522 * volume;
		pedra = 0.768 * volume;
		agua = 210 * volume;

		printf("\nQuantidade necessárias: \n");
		printf("Cimento: %.2f sacos de 50kg\n", cimento);
		printf("Areia: %.2f metros cubicos\n", areia);
		printf("Pedra: %.2f metros cubicos\n", pedra);
		printf("Agua: %.2f litros\n", agua);
		break;
	case 3:
		printf("A proporcao dos materiais para o concreto de contrapiso ou calçada e de 1:3:6 sendo cimento, areia e pedra respectivamente, a agua e "
			"medida em funcao do volume de concreto, sendo 168 litros por metro cubico.\n");
		cimento = 4.2 * volume;
		areia = 0.564 * volume;
		pedra = 0.882 * volume;
		agua = 168 * volume;

		printf("\nQuantidade necessarias: \n");
		printf("Cimento: %.2f sacos de 50kg\n", cimento);
		printf("Areia: %.2f metros cubicos\n", areia);
		printf("Pedra: %.2f metros cubicos\n", pedra);
		printf("Agua: %.2f litros\n", agua);
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

	printf("Quantidade de concreto necessaria: %.2f metros cubicos", volume);
	
}

void calculaTijolos(){

	printf("\nO calculo do numero de tijolos e feito com base na area das paredes, onde devemos levar em conta suas dimensoes e "
	"espacos reservados, como de portas e janelas. Alem disso se deve considerar as dimensoes do tijolo e a quantidade de argamassa "
	"entre os tijolos\n");

	int opcao;
	float comprimentoT, alturaT, argamasssaT, areaT;
	float comprimentoP, alturaP, areaBruta;
	float comprimentoJ = 0, alturaJ = 0, areaJ = 0;
	float areaLiquida;

	printf("\nPara comecar informe as dimensoes do tijolo (em metros)\n");
	printf("Informe o comprimento: ");
	scanf("%f", &comprimentoT);
	printf("Informe a altura: ");
	scanf("%f", &alturaT);
	printf("Agora informe a espessura da argamassa: ");
	scanf("%f", &argamasssaT);
	areaT = (comprimentoT + (argamasssaT/2)) * (alturaT + (argamasssaT/2));

	do{		
		printf("\nAgora informe as dimensoes das paredes, portas e janelas\n");
		printf(	"1 - Adicionar parede\n"
				"2 - Reduzir area de janela ou porta\n"
				"3 - Finalizar\n");
		printf("Informe o numero da opcao: ");
		scanf("%d", &opcao);

		switch (opcao)
		{
		case 1:
				printf("Informe o comprimento: ");
				scanf("%f", &comprimentoP);
				printf("Informe a altura: ");
				scanf("%f", &alturaP);
				areaBruta += (comprimentoP * alturaP);
			break;
		case 2:
				printf("Informe o comprimento: ");
				scanf("%f", &comprimentoJ);
				printf("Informe a altura: ");
				scanf("%f", &alturaJ);
				areaJ += (comprimentoJ * alturaJ);
			break;
		case 3:
				opcao = 3;
			break;		
		default:
			printf("Opcao invalida!");
			break;
		}

		areaLiquida = areaBruta - areaJ;

		printf("\nArea bruta: %.2f\n", areaBruta);
		printf("Area liquida: %.2f\n", areaLiquida);
		printf("Total de tijolos: %.2f\n", (areaLiquida/areaT));



		/* code */
	} while (opcao != 3);
	
}











