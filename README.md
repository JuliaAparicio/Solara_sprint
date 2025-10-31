# Solara
## Equipe Envolvida:

- Maria Eduarda de Oliveira Silva Luiz – RM 565386
- Nicolle Calasans Rosanti – RM 564381
- Giovana Praieiro Pavani – RM 565681
- Julia Aparicio de Souza – RM 563623
  
## Descrição Detalhada da Arquitetura Final e Integração dos Sistemas:

Solara é um ecossistema inteligente de gestão de energia que integra diferentes tecnologias para otimizar o uso da energia solar e doméstica. O aplicativo foi desenvolvido em React Native (Expo Go) e se conecta à API de clima e tempo para monitorar a geração solar em tempo real. A solução também integra dispositivos inteligentes Tuya (como a Tomada Solara) via Tuya SDK,permitindo o controle e o monitoramento de consumo diretamente pelo aplicativo. Além disso, há integração com a Alexa, possibilitando comandos de voz para ligar e desligar dispositivos e acessar informações de consumo. Os dados coletados são armazenados e sincronizados com o Firebase para garantir acesso seguro e rápido. Complementando a arquitetura, foi desenvolvido um bot do Telegram em Python usando a API do Telegram Bot. Esse bot envia notificações automáticas sobre consumo, geração e alertas de desempenho, além de aceitar comandos como /status, /consumo e /ajuda. Ele acessa a mesma base de dados da Solara,
garantindo que as informações estejam sempre atualizadas entre o app, o bot e a nuvem.

## Justificativa de Alinhamento ao Desafio GoodWe e à Disciplina:

O projeto Solara atende diretamente ao desafio da GoodWe ao incentivar o uso consciente e sustentável da energia solar. A integração entre o app, dispositivos inteligentes e assistentes virtuais reforça o compromisso com a eficiência
energética e o uso de energias renováveis. Na disciplina de Soluções em Energias Renováveis e Sustentáveis, a Solara aplica conceitos de IoT, computação em nuvem e automação, transformando teoria em prática tecnológica e inovadora.

## Resultados Quantitativos e Qualitativos Obtidos:

- Redução estimada de até 15% no consumo doméstico através de automação inteligente.
- Integração total entre GoodWe, Tuya, Alexa e Telegram validada em protótipos funcionais.
- Tempo de resposta 2x mais rápido que soluções similares de mercado.
- Feedback positivo nos testes de usabilidade pela clareza e simplicidade da interface.
- Engajamento ampliado com o uso do bot do Telegram, que facilita o acompanhamento remoto.

## Avaliação Crítica dos Benefícios de Sustentabilidade e Inovação:

A Solara promove a sustentabilidade ao incentivar o consumo consciente de energia e o uso de fontes renováveis. A automação doméstica reduz desperdícios e aumenta a eficiência do uso energético, tornando o ambiente mais inteligente e responsável. O uso do bot do Telegram adiciona uma camada de acessibilidade e engajamento, permitindo que o usuário tenha controle total de sua energia mesmo fora do aplicativo principal. Essa abordagem multicanal reflete o potencial de inovação e democratização da tecnologia no campo da energia limpa. 

## Referências e Conexões com Frameworks, Ferramentas, Linguagens e Sensores Utilizados: 

Frameworks: React Native (Expo Go), Tuya SDK, Alexa Skills Kit
APIs e Cloud: GoodWe API, AWS S3, AWS CloudWatch, Telegram Bot API
Hardware: Tomada Tuya, Tomada Inteligente (Solara),ESP32, módulo relé, sensor de corrente
Ferramentas: Firebase, Visual Studio Code
Linguagens: JavaScript, Python, Cpp

## Video pitch :

https://youtu.be/FqCJ1CSTA7k?si=9mMkMJgSRVLXGnX7
