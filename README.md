# Banco
🤑🏛️💰 Implementação de um banco financeiro utilizando a linguagem C.
## Funcionamento
UM programa que armazena os dados referentes a conta corrente de vários clientes de um banco.
No banco não é permitido conta conjunta, ou seja, uma conta só pertence a um cliente. No entanto,
um cliente pode possuir mais de uma conta.

O programa deve possui as seguintes funcionalidades:
1. Cadastrar cliente
2. Alterar cliente
3. Cadastrar conta
4. Alterar conta
5. Remover conta
6. Mostrar saldo
7. Deposito
8. Saque
9. Transferência
10. Contas de um cliente
11. Dados dos clientes com saldo inferior, superior ou igual a um valor
12. Lista os dados cadastrais de todos clientes (ativos ou não)
13. Listar as informações de todas as contas
14. Listas as informações de todos os clientes (inclusive as informações referentes as suas contas)
15. Listar os dados cadastrais de todos clientes de uma agencia(ativos) ordenados pelo CPF

## Explicação das funcionalidades

1) O cadastro deve ser feito um a um e não todos de uma vez, ou seja, para essa funcionalidade
implemente uma função que quando chamada será responsável pelo cadastro de um cliente. Os
clientes são importantes para o banco e uma vez cadastrados, suas informações não são
removidas, mesmo que suas contas sejam canceladas.
Os dados a serem armazenados para cada cliente são, pelo menos:
- nome completo
- CPF (cadeia de caracteres)
- endereço
- telefone principal
- email principal
- numero de contas (indica o número de contas de um cliente!!! iniciar com zero!!!)


2) Deve ser possível alterar os dados cadastrais de um cliente, para tanto o usuário deve fornecer
o CPF e para o cliente do CPF em questão deve ser exibido um menu para que o usuário escolha
o que deseja alterar:
1. Nome
2. CPF
3. Endereco
4. Telefone principal
5. Email principal
0. Sair
Esse menu deve ser exibido até o usuário escolher a opção Sair.

3) O cadastro deve ser feito um a um e não todos de uma vez, ou seja, para essa funcionalidade,
implemente uma função que quando chamada será responsável pelo cadastro de uma conta.
Os dados a serem armazenados para cada conta são, pelo menos:
- numero da agencia (inteiro)
- número da conta (inteiro),
- saldo (float)
- cliente (CPF do cliente dono da conta)

- Um mesmo cliente pode possuir mais de uma conta corrente, portanto é permitido mais de uma
conta com o mesmo CPF. Toda vez que for criado uma conta para um cliente, incremente o campo
“numero de contas” do cliente em questão.

4) Deve ser possível alterar os dados cadastrais de uma conta bancária, para tanto o usuário deve
fornecer o número da agência e número da conta. Para essa conta em questão deve ser exibido
um menu para que o usuário escolha o que deseja alterar:
1 – Numero da agencia
2 – Numero da conta
3 – CPF
0 – Sair
Esse menu deve ser exibido até o usuário escolher a opção Sair.

5) Deve ser possível cancelar uma conta de um cliente (remover!!!), para tanto basta que ele
informe o número da conta e numero da agencia. Se não existir nenhuma conta corrente com
esse numero de conta e numero de agência, informe: CONTA INVALIDA! e retorne para o menu.

6) Deve ser possível que o cliente consulte seu saldo, para isso basta que ele informe o número da
conta e o numero da agencia. Se não existir nenhuma conta corrente com esse numero de conta
e numero de agência, informe: CONTA INVALIDA! e retorne para o menu.

7) Deve ser possível que um cliente faça um depósito, para tanto ele deve informar o número da
conta, o numero da agência e o valor do depósito. Se não existir nenhuma conta corrente com
esse numero de conta e numero de agência, informe: CONTA INVALIDA! e retorne para o menu.

8) Deve ser possível que um cliente faça um saque, para tanto ele deve informar o número da
conta, o numero da agência e o valor a ser sacado. Se não existir nenhuma conta corrente com
esse numero de conta e numero de agência, informe: CONTA INVALIDA! e retorne para o menu.
Se o valor a ser sacado for maior do que o valor que o cliente possui, não realize o saque e
informe apenas: SALDO INSUFICIENTE. e retorne para o menu.

9) Deve ser possível que o cliente transfira um valor de uma conta corrente para outra, para tanto
o cliente deve informar o numero da conta e o numero da agencia tanto da conta destino, como
da conta origem. Além disso, deve informar o valor que será transferido.

10) Deve ser possível obter informações de todas as contas correntes (numero da conta, numero da
agencia e saldo) de um cliente. Para isso, o usuário deve informar apenas o CPF do cliente que
uma lista com essas informações será apresentada na tela do programa.

11) Deve ser possível exibir na tela do programa os dados das contas correntes(nome do cliente,
CPF do cliente, numero da conta, numero da agencia e saldo) que possuem saldo menor, maior
ou igual a um determinado valor. Você deve perguntar o valor desejado e, em seguida, perguntar
se o usuário deseja as informações das contas com saldo maior, menor ou igual a esse valor (1
– maior, 0 – igual, -1 – menor). Deve haver também uma opção de salvar essas informações em
um arquivo texto.

12) Deve ser possível listar os dados cadastrais de todos os cliente (não precisa informação sobre as
contas). Deve haver também uma opção de salvar essas informações em um arquivo texto.

13) Listar as informações sobre todas as contas, inclusive o nome e CPF do dono da conta (endereço
e telefone não são necessários). Deve haver também uma opção de salvar essas informações
em um arquivo texto.

14) Listar as informações sobre todos os clientes (caso o cliente possua conta(s), liste as informações
dessa(s) conta(s), caso não possua nenhuma conta, apenas informe isso). Deve haver também
uma opção de salvar essas informações em um arquivo texto.

15) Listar os dados cadastrais de todos clientes de uma agencia(ativos) ordenados pelo CPF

## Menus
Todas as funcionalidades devem ser acessadas através dos seguintes menus:

MENU PRINCIPAL
1. Cliente
2. Conta
3. Movimento
4. Relatorio
0. Sair

MENU CLIENTE
1. Cadastrar Cliente
2. Alterar Cliente
0. Sair

MENU CONTA
1. Cadastrar Conta
2. Alterar Conta
3. Remover Conta
0. Sair

MENU MOVIMENTO
1. Deposito
2. Saque
3. Transferência
0. Sair

MENU RELATORIOS
1. Contas de um cliente
2. Dados dos clientes com saldo inferior, superior ou igual a um valor
3. Lista os dados cadastrais de todos clientes (ativos ou não)
4. Listar as informações de todas as contas
5. Listas as informações de todos os clientes (inclusive as informações referentes as suas contas)
6. Listar os dados cadastrais de todos clientes de uma agencia(ativos) ordenados pelo CPF
0. Sair
