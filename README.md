Projeto 1 – Mobilidade Sustentável
Guia de Montagem e Execução do Protótipo

Este protótipo simula uma competição entre dois jogadores, que respondem perguntas sobre mobilidade sustentável usando volantes com três botões cada. Ao acertar uma pergunta, a esteira daquele jogador avança e empurra um carrinho. O primeiro a chegar ao final vence.

Este README explica como replicar o protótipo de forma simples, usando as mesmas peças e lógica que utilizamos.

1. Estrutura Física do Protótipo

A parte física é formada por três seções principais:

• Volantes e Totem

Ambos os volantes ficam fixados em um totem de MDF, com estrutura vertical reforçada.
Cada volante foi montado com:

Um eixo feito com cano PVC, permitindo giro suave.

Três botões:

Dois pequenos (esquerda e direita)

Um botão grande de fliperama (opção do meio)

O PVC serve como suporte e rolamento, garantindo que o volante gire naturalmente.

• Esteiras

As duas esteiras foram montadas de forma simples e eficiente usando:

Base de MDF para sustentação

Papelão + canudos para formar o tapete rolante

Cada lado possui um motor dedicado que puxa o papelão e faz o carrinho avançar

Os carrinhos usados são modelos leves de brinquedo

Esse mecanismo funciona como uma mini esteira: ao acionar o motor por alguns segundos, o papelão gira e movimenta o carrinho.

2. Componentes Eletrônicos

O sistema usa:

1 Arduino Uno para toda a lógica do jogo

2 ESP32 dedicados ao controle dos motores das esteiras

2 motores (um para cada esteira)

6 botões (3 para cada volante)

Todos os botões foram ligados como entradas com INPUT_PULLUP, e cada motor é ativado pelo microcontrolador correspondente por 2 segundos quando o jogador acerta.

3. Funcionamento do Jogo

As perguntas são impressas em papel.

O professor/monitor lê cada pergunta e suas três opções.

O jogador responde girando o volante:

Girou para a esquerda → opção 1

Aperta o botão grande central → opção 2

Girou para a direita → opção 3

O Arduino registra a resposta de ambos.

Se o jogador acertar:

O motor da sua esteira liga por 2 segundos

O carrinho avança

O jogo segue por 9 perguntas.

Ao final, o Arduino exibe o placar no Serial Monitor.

O código completo está no arquivo .ino deste repositório.

4. Como Executar o Protótipo

Monte todos os botões nos volantes e conecte aos pinos digitais do Arduino.

Conecte cada motor ao seu ESP32 ou ao driver correspondente.

Suba o código no Arduino Uno pelo Arduino IDE.

Ligue os ESP32 e os motores com fonte externa adequada.

Teste cada botão antes de iniciar.

Comece a rodada lendo a primeira pergunta impressa.

Acompanhe as respostas e observe a movimentação das esteiras.

5. Objetivo Educacional

O protótipo foi desenvolvido para aproximar os participantes dos princípios da mobilidade urbana sustentável, transformando conceitos teóricos em uma experiência prática e dinâmica. A cada pergunta respondida, o jogo estimula uma reflexão sobre como nossas escolhas diárias — como caminhar, usar bicicleta, optar por transporte público ou evitar deslocamentos desnecessários — impactam diretamente o trânsito, a qualidade do ar, o consumo de energia e o planejamento das cidades.

A mecânica competitiva ajuda a manter o engajamento, mas a intenção principal é promover consciência ambiental de forma leve: ao acertar, o carrinho avança na “trilha” da mobilidade sustentável, simbolizando o progresso que decisões responsáveis geram no coletivo. O jogo também reforça temas como redução de emissões, eficiência energética, acessibilidade urbana, compartilhamento de modais e o papel da população na construção de cidades mais saudáveis.

Mais do que testar conhecimentos, o projeto funciona como uma ferramenta de sensibilização, mostrando que escolhas individuais têm impacto real no ambiente urbano — e que a construção de um sistema de mobilidade mais sustentável depende exatamente dessa mudança de percepção.
