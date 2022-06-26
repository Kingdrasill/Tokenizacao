# Tokenização e Ranqueamento de Documentos

<div style="display: inline-block;">
<img align="center" height="20px" width="60px" src="https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white"/> 
<img align="center" height="20px" width="80px" src="https://img.shields.io/badge/Made%20for-VSCode-1f425f.svg"/> 
<a href="https://github.com/mpiress/midpy/issues">
</a> 
</div>

- <h2>Problema</h2>
  <p align="justify"> Como é de conhecimento de todos, as estruturas do tipo lista, pilha e filha formam a base
  da estrutura de dados e são amplamente utilizadas como parte de muitos problemas atuais.
  Sua função é adaptar tais estruturas para um problema de contagem de palavras em um texto.
  Como entrada, a aplicação receberá um conjunto de documentos D = {<i>d<sub>1</sub>, d<sub>2</sub>, . . . , d<sub>n</sub></i>}, os
  quais devem ser processados via tokenização, onde, as palavras são extraída e armazenadas.
  Nesse processo, tem-se o que chamamos de stop words (vide, https://gist.github.com/
  alopes/5358189), que devem ser desconsideradas na avaliação. Por fim, utilize dos conceitos
  de TF/IDF (vide, https://rockcontent.com/br/blog/tf-idf/) para ranquear os documentos
  sob a importância de suas palavras. Considere textos em inglês para evitarmos erros com
  acentuação. Considere realizar esse problema a partir das seguintes fases:
  
    1- Realizar a tokenização dos documentos e separação das stop words.
    
    2- Aplicação do TF/IDF nas palavras encontradas seguindo sua base teórica.
    
    3- Utilizando uma entrada com algumas palavras, mostrar em ordem de importância os documentos avaliados. </p>

# Custo Computacional

# Estrutura do Problema

- <h2>Estrutura utilizada</h2>

	<p align="justify">
	Primeiramente, o motivo da escolha da Lista Dinâmica se deu ao fato de que era a estrutra mais conveniente a ser utilizada para este problema. A Fila não era a estrutura ideal por possibilidar a remoção de elementos somente no início e no final. A Pilha tem o mesmo problema, além de que o último elemento que entra sempre será o primeiro a ser removido. Logo, a Lista é a que oferece a maior gama de possibilidades dentre aquelas que são úteis para o desenvolvimento da solução.

	A lista dinâmica é uma variante do modelo estático [vide git](https://github.com/mpiress/linear_list). Assim, antes de apresentar as modificações existêntes nessa implementação, vejamos uma representação gráfica do modelo dinâmico em questão. Observe as nomenclaturas utilizadas na figura, essas são utilizadas na implementação fornecida, as quais podem estar definidas/parametrizadas no idioma inglês.
	</p>

	<p align="center">
		<img src="imagens/lista.png"/> 
	</p>

	<p align="justify">
	Note pela figura que, o primeiro bloco armazenado em RAM não apresenta o tipo dado como parte da estrutura, mas sim um valor 0 <b>"simbólico"</b>. Isso porque é preciso inserir na estrutura o que chamaremos de cabeça da lista. A cabeça de uma lista nada mais é que um ponteiro <i>vazio</i> (i.e., um tipo similar ao void) que indica qual posição de memória será utilizada como base/início da lista. 
	</p>

	<p align="justify">
	Uma outra nomenclatura a ser observada na figura é a existência de um ponteiro <b>prox</b>. Este tem por objetivo apontar para o próximo bloco de memória que conterá o novo dado ou para NULL, o que facilita a navegação entre os blocos e a identificação do fim da lista. Este ponteiro se mostra imprescindível, uma vez que abandonamos o modelo sequencial de memória e adotamos um conceito cujos blocos estão em endereços aleatórios. Nesse novo modelo, inserções, remoções, pesquisas e impressões da lista são apoiadas por dois outros ponteiros, o <b>primeiro</b> e o <b>último</b>, conforme representação da figura.
	</p>

	> Qual a função dos ponteiros <b>primeiro</b> e <b>ultimo</b>?
	>
	> Como a lista é composta de blocos espalhados na memória, torna-se necessário identificar qual bloco representa a cabeça da lista. Para isso, é utilizado o ponteiro primeiro. Da mesma forma, identificar o último bloco também se torna importante, uma vez que, novas inserções são realizadas sempre no final dessa estrutura com o objetivo de facilitar sua manipulação.

	<p align="justify">
	Se considerarmos um computador hipotético com 8Mb de RAM distribuídos em dois pentes de 4Mb cada, uma representação da lista dinâmica poderia ser compreendida da seguinte forma:
	</p>

	<p align="center">
		<img src="imagens/memoria.png"/> 
	</p> 

	<p align="justify">
	Dado o exemplo de distribuição da lista dinâmica em memória apresentado na figura acima, é possível notar que os procedimentos de tratamento dessa estrutura não são tão triviais quanto os utilizados pela vertente estática baseada em vetor. Em resumo, para coordenar essa nova estrutura, é preciso adotar no mínimo as seguintes funções:
	</p>

	<p align="justify">
	1. <b>FLVazia</b>: Função responsável por criar um espaço de memória para ser a <i>cabeça</i> da lista. Para tanto, é utilizado a chamada de função nativa do C/C++ <b>malloc</b>, o qual recebe como referência o espaço a ser reservado por meio da diretriz <b>sizeof</b>. Nesse primeiro momento, o <i>casting</i> (i.e., conversão de um tipo void criado pelo malloc para um tipo específico) se torna opcional, sendo utilizado na codificação apenas para manter um único padrão de definição de função. Como pode ser observado no código disponibilizado, o endereço produzido pela execução do malloc é copiado para o ponteiro primeiro e último, mantendo ambos no mesmo endereço. O que significará que a lista se encontra vazia. Por fim, apontamos o prox de ambos os ponteiros para NULL.
	</p>

	<p align="justify">
	2. <b>Inserir</b>: Para inserir elementos na lista, a primeira ação a ser realizada é reservar espaço em memória para esse novo dado. Para isso, o apontador último deve apontar em memória para o endereço do novo bloco cujo prox apontará para NULL.  
	</p>

	>Dica para inserções:
	>
	>Quando a lista é criada (i.e., execução do FLVazia), os ponteiros estão apontando para a "cabeça da lista". Essa posição de memória não deve ser utilizada para armazenar dados. Então, para cada novo bloco a ser armazenado deve-se reservar uma nova área na memória. Esse procedimento é realizado pelo malloc e o local a ser guardado esse novo endereço é no ponteiro que representa o próximo (i.e., prox). Nesse contexto, os novos endereços que são criados sempre são recebidos pelo ponteiro prox do último bloco existente, ou seja, o que está referenciado pelo ponteiro de último. Veja um pequeno exemplo desse processo a partir da figura a seguir. 

	<p align="center">
		<img src="imagens/inserir.png"/> 
	</p> 

	<p align="justify">
	<b>Remover</b>: Para remover um bloco, primeiro é preciso testar se lista não está vazia, i.e., primeiro != último. Se estiverem apontando para o mesmo endereço, um erro é apresentado e a função finalizada. Caso contrário, é preciso pesquisar o bloco na lista antes de removê-lo. Para isso, é preciso utilizar um apontador auxiliar (i.e., aux) para receber o endereço da cabeça da lista. Uma vez que, a cabeça da lista não possui dado valido, é realizada a validação sempre utilizando a próxima posição e diferente de NULL. Note que no laço while dentro do código disponibilizado é realizado exatamente isso, avançando o ponteiro aux para o próximo, comparando o bloco encontrado com o dado a ser removido. Ao término do laço testa-se se a variável aux não é NULL, ou seja, não chegou ao final da lista sem achar o valor desejado. Se o dado foi localizado, ele estará no endereço de aux a partir de seu prox, então, para remover esse dado é preciso literalmente pula-lo na sequencia de ligações dos ponteiros. Para isso, cria-se uma segunda variável para receber o endereço de aux e avançamos a variável aux para a posição exata do dado a ser removido. Feito isso, o prox do novo ponteiro de apoio ao aux é ligado ao prox do bloco a ser removido e que está sendo apontado por aux. Por fim, libera-se a memória utilizando-se a função nativa free em aux. Veja a representação desse processo através do exemplo da figura abaixo. 
	</p>

	<p align="center">
		<img src="imagens/remover.png"/> 
	</p> 
	
	Nossa estrutura é um pouco diferente da estrutura convencional de listas dinâmicas, pois consiste em várias Listas Dinâmicas dentro de si mesmas. A partir do seguinte trecho de código é possível entender a organização:
	
	Vamos entender os passos do mais específico para o mais generalista. No arquivo "palavra.hpp", a <i>struct</i> "Word" armazena alguns dados sobre uma palavra específica, que são: a própria palavra numa <i>string</i>, a quantidades de vezes que a palavra apareceu num <i>short int</i>, o valor ASCII da palavra (resultado da soma do valor ASCII de cada caractere) num <i>short int</i>, a inicial da palavra num <i>char</i> e o resultado do cálculo de TF/IDF da palavra num <i>float</i>.
	
	<p align="center">
		<img src="imagens/palavraHPP.png"/> 
	</p>
	
	Já em "listPals.hpp", a <i>struct</i> "Palavras" possui uma lista de palavras de um certo tamanho, a quantidade de palavras e o tamanho em uma variável <i>int</i>.
	
	<p align="center">
		<img src="imagens/listPalsHPP.png"/> 
	</p>
	
	Além disso, "documento.hpp" possui uma <i>struct</i> chamada "Documento" com uma lista de listas de palavras dividido pelo tamanho delas. Cada lista armazena palavras de um certo tamanho. Por exemplo: a lista 1 armazena palavras de tamanho N, a lista 2 armazena palavras de tamanho N+1. Ademais, possui uma variável do tipo <i>string</i> para guardar o nome do documento, a quantidade de palavras no documento em um <i>int</i> e um <i>float</i> para guardar dados do TF/IDF futuramente.
	
	<p align="center">
		<img src="imagens/documentoHPP.png"/> 
	</p>

- <h2>Método de remoção das stop words</h2>

- <h2>Método de busca</h2>

- <h2>TF/IDF</h2>
	TF-IDF é um cálculo estatístico que mede a importância de uma palavra em um texto quando comparado com uma coleção maior de outros documentos. Se uma palavra aparece muitas vezes em um documento, a palavra se torna mais importante. Mas quando essa palavra também aparece frequentemente em outros documentos, ela perde importância.
	
	TF-IDF significa <i>Term Frequency – Inverse Document Frequency</i>. Essa expressão pode ser traduzida para o português como “Frequência do Termo – Frequência Inversa dos Documentos”.
	
	TF se refere à “frequência do termo”. Essa parte do cálculo responde à pergunta: com que frequência o termo aparece nesse documento? <b>Quanto maior for a frequência no documento, maior será a importância do termo.</b>

	Já o IDF significa “frequência inversa dos documentos”. Nessa parte, a ferramenta responde: com que frequência o termo aparece em todos os documentos da coleção? <b>Quanto maior for a frequência nos documentos, menor será a importância do termo.</b>

	O cálculo do IDF considera que termos que se repetem frequentemente nos textos — como artigos e conjunções (a, o, e, mas, que etc.) — não têm relevância para os documentos e, no caso do Google, para a indexação e o rankeamento.

	Então, quando o fator IDF é incorporado, o cálculo diminui o peso dos termos que ocorrem com muita frequência no conjunto de documentos e aumenta o peso dos termos que ocorrem raramente. Este esquema ajuda a entender melhor:
	
	<p align="center">
		<img src="imagens/esquema.png"/> 
	</p> 
	
	<h3>Limitações do TF/IDF</h3>

	- <h4>Palavras-chave e intenção</h4>
			Ao focar apenas nas primeiras páginas nos resultados de pesquisa, as ferramentas TF-IDF SEO (<i>Search Engine Optimization</i>) correm o risco 				de analisar páginas que não são realmente seus concorrentes. Eles também podem segmentar sites que operam em nichos diferentes do seu próprio site.
			Além disso, o conteúdo desses sites pode ser muito longo ou superficial demais para fornecer uma comparação útil com seu próprio conteúdo.
			
	- <h4>Limitações de tamanho da amostra</h4>
			O banco de dados do Google para TF-IDF consiste em todas as páginas da Internet que ele indexou. Nenhuma outra ferramenta de SEO tem acesso a 				esse banco de dados. Como resultado, o melhor que eles podem fazer é usar estimativas aproximadas, com precisão incerta.
			Na verdade, as ferramentas TF-IDF frequentemente examinam apenas as 10 ou 20 principais páginas dos resultados de pesquisa do Google.
			
	<h3>Implementação do TF-IDF no código</h3>
	
	- <h4>TF</h2>
		<p align="center">
			<img src="imagens/TF.png"/> 
		</p> 
		Escrever aqui
		
	- <h4>IDF</h2>
		<p align="center">
			<img src="imagens/IDF.png"/> 
		</p> 
		Escrever aqui
	

# Resultados

# Conclusão

# Participantes

- Bárbara Braga Gualberto Correa<br>
<a href="https://github.com/barbrina" target="_blank"><img src="https://img.shields.io/badge/GitHub-100000?style=for-the-badge&logo=github&logoColor=white" target="_blank"></a><a href="https://www.linkedin.com/in/barbara-gualberto/" target="_blank"><img src="https://img.shields.io/badge/LinkedIn-0077B5?style=for-the-badge&logo=linkedin&logoColor=white" target="_blank"></a>

- Gabriel Couto Assis<br>
<a href="https://github.com/Couto1411" target="_blank"><img src="https://img.shields.io/badge/GitHub-100000?style=for-the-badge&logo=github&logoColor=white" target="_blank"></a><a href="https://www.linkedin.com/in/gabriel-couto-582060200/" target="_blank"><img src="https://img.shields.io/badge/LinkedIn-0077B5?style=for-the-badge&logo=linkedin&logoColor=white" target="_blank"></a>

- Gabriel Teixeira Júlio<br>
<a href="https://github.com/Kingdrasill" target="_blank"><img src="https://img.shields.io/badge/GitHub-100000?style=for-the-badge&logo=github&logoColor=white" target="_blank"></a><a href="https://www.linkedin.com/in/gabrielteixeirajulio/" target="_blank"><img src="https://img.shields.io/badge/LinkedIn-0077B5?style=for-the-badge&logo=linkedin&logoColor=white" target="_blank"></a>

- Kemily Rezende Silva<br>
<a href="https://github.com/KemilyRezende" target="_blank"><img src="https://img.shields.io/badge/GitHub-100000?style=for-the-badge&logo=github&logoColor=white" target="_blank"></a><a href="https://www.linkedin.com/in/kemily-rezende-b89918212/" target="_blank"><img src="https://img.shields.io/badge/LinkedIn-0077B5?style=for-the-badge&logo=linkedin&logoColor=white" target="_blank"></a>

- Marcus Vinícius Nogueira Santos<br>
<a href="https://github.com/mkssantos" target="_blank"><img src="https://img.shields.io/badge/GitHub-100000?style=for-the-badge&logo=github&logoColor=white" target="_blank"></a><a href="https://www.linkedin.com/in/marcus-santos-9412b5207/" target="_blank"><img src="https://img.shields.io/badge/LinkedIn-0077B5?style=for-the-badge&logo=linkedin&logoColor=white" target="_blank"></a>

- Pablo Sousa da Silva<br>
<a href="https://github.com/pablossousa" target="_blank"><img src="https://img.shields.io/badge/GitHub-100000?style=for-the-badge&logo=github&logoColor=white" target="_blank"></a><a href="https://www.linkedin.com/in/pablo-silva-734b22202/" target="_blank"><img src="https://img.shields.io/badge/LinkedIn-0077B5?style=for-the-badge&logo=linkedin&logoColor=white" target="_blank"></a>

- Thaissa Vitória Guimarães Daldegan de Sousa<br>
<a href="https://github.com/thaissavitoria" target="_blank"><img src="https://img.shields.io/badge/GitHub-100000?style=for-the-badge&logo=github&logoColor=white" target="_blank"></a><a href="https://www.linkedin.com/in/thaissa-vitoria-daldegan-6a84b9153/" target="_blank"><img src="https://img.shields.io/badge/LinkedIn-0077B5?style=for-the-badge&logo=linkedin&logoColor=white" target="_blank"></a>
