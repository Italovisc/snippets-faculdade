def main():
    # Explicação ao usuário e criação de lista que armazenará os inputs
    print("Digite suas frases. Digite 'sair' para terminar e salvar o arquivo.")

    frases = []

    # Loop que se manterá enquanto o usuário escrever palavras, na qual estas serão armazenadas na lista 'frases'
    while True:
        entrada = input("> ")

        if entrada.lower() == "sair":
            break

        frases.append(entrada)
    
    # Criação do arquivo com as frases coletadas
    with open("meu_arquivo_out.txt", "w", encoding="utf-8") as arquivo:
        for frase in frases: 
            arquivo.write(frase + "\n")

    # Criação da lista que armazenará as frases modificadas, leitura do arquivo e processo de modificação
    dados_modificados = []

    with open("meu_arquivo_out.txt", "r", encoding="utf-8") as arquivo:
        for linha in arquivo:
            dados_modificados.append(linha.strip().upper())
    
    # Modificação do arquivo original com a nova formatação
    with open("meu_arquivo_out.txt", "w", encoding="utf-8") as arquivo:
        for linha in dados_modificados:
            arquivo.write(linha + "\n")
    
    print("\nO arquivo foi sobrescrito com os dados modificados")


if __name__ == "__main__":
    main()
