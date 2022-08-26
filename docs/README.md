        Pipeline:
        Entrada:
            - via terminal as opções para gerar senha (nome do destino, login, tamanho da chave)
            - via CLI com menu
        Saida:
            - cospe a senha da opção escolhida
        
        Algoritmo:
            1. inicio
            4. espera login ou comando pra criar um novo usuario
                - login
                    - pede login e senha
                    - exporta chave AES do token
                    - desempacota a chave do aes
                    - 
                - cadastrar novo usuario
                    - inicializa token
                    - gera chave AES no token
                    - gera par RSA no PC
                    - armazena a pub gerada no token e a priv no pc
                    - cria um database de chaves pro usuario
                    - anota no databse qual o arquivo de senhas do usuario e a chave publica assimetrica
            5. quando logado aperece o menu:
                - criar nova senha
                    - opções de tamanho de chave:
                        - 16 carac
                        - 12 carac
                        - 8 carac
                    - gera a chave do tamanho escolhido com randint
                    - importa a chave aes e descriptografa com a rsa
                    - criptografa a senha com a chave aes
                    - criptografa o nome da senha com a chave aes
                    - salva a senha com o nome no database de senhas
                    - apresenta a senha pro usuario
                    - limpa o buffer da chave e da senha e dos databases
                - obter senha
                    - hash o nome da chave inserido
                    - busca o valor criptografado
                    - caso search hit, importa a chave aes e descriptografa com a rsa
                    - descriptografa a senha com a chave aes
                    - printa a senha
                    - limpa o buffer da chave, senha e database
                - deletar senha
                    - hash o nome da chave inserido
                    - pede confirmação
                    - deleta a linha caso exista 
                - modificar senha
                    - hash o nome da chave inserido
                    - procura a chave na tabela
                        - caso exista
                            - pede confirmação
                            - procedimento de criar nova senha
                        - caso nao exista, printa erro
                - alterar PIN do token
                    - pede PIN antigo
                    - pede PIN novo