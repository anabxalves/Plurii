# 👁 Plurii - Monitoramento Educacional

![GitHub repo size](https://img.shields.io/github/repo-size/iuricode/README-template?style=for-the-badge)

<img src="./assets/SR2.jpg" alt="equipe-plurii">

> Unindo experiências para criar soluções Plurais!
---

## 🏥 Cliente

O Hospital das Clínicas da Universidade Federal de Pernambuco Professor Romero Marques (HC-UFPE) é um órgão suplementar da UFPE de apoio ao ensino, pesquisa extensão e assistência ep resta serviços médicos especializados de média e alta complexidade acobertados pelo SUS. Faz parte do grupo de 44 hospitais universitários geridos pela Rede Ebserh (Empresa Brasileira de Serviços Hospitalares).
- O HC auxilia no campo de prática na formação de estudantes e profissionais incluindo:
  - 15 cursos de graduação; 
  - 52 programas de residência uniprofissional e multiprofissional;
  - 13 cursos de pós-graduação.

## 👊 Problemática

Como otimizar o monitoramento da jornada dos residentes do HC garantindo a assertividade das informações?
  - Devido aos diversas especialidades de de Residência com formas de avaliação e acompanhamento diferentes  há uma grande dificuldade no Monitoramento da Jornada dos Residentes. Isso é agravado também pois os residentes não recebem feedback das atividades e as avaliações e frequencias são registrados tardiamente e em formulários de papel.

## 😎 Solução

Uma aplicação web responsiva com interface gameficada para o registro de frequencia, avaliação e feebback das atividades dos residentes de forma assertiva e instantânea para a melhoria do monitoramento dos programas residências no Hospital das Clínicas UFPE.
- Nosso processo de desenvolvimento da solução foi dividido em dois momentos: 
  - Aquisição de dados e foco no  engajamento dos residentes e preceptores através da gameficação para garantir o recebimentos dos dados de forma assertiva;
  - Após validar a primeira parte, o foco foi no refinamento  da solução para abarcar as necessidades das coordenações e núcleo de  Gestão de Educação Pesquisa para gestão e manipulação de dados e criação de métricas de avaliação de qualidade estabelecidas com o cliente.

## 🚀 Linguagem utilizada
- <img src="https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white" />

## ⚙️ Instruções de uso

1. O código pode ser executado tanto pelo .exe presente no repositório, quanto clonar o repositório para o Replit.
2. Usuários de acesso:
   - Preceptor:
       - Usuário: mferreira
       - Senha: 1234
   - Residente:
       - Usuário: msantos
       - Senha: 1234
3. Navegue pelos menus e funcionalidades através dos números:
    - Menu Preceptor:
      - 1: Frequência
      - 2: Avaliações/Feedback
      - 3: Atividade Diária
      - 4: Calendário Acadêmico
      - 5: Residentes
      - 0: Sair
   - Menu Residente:
     - 1: Frequência
     - 2: Avaliações
     - 3: Feedbacks
     - 4: Calendário Acadêmico (EM DESENVOLVIMENTO)
     - 0: Sair

## 📄 Como foi desenvolvido?

1. Iniciamos tendo em mente a nossa planilha de estrutura de dados, com isso criamos as libs que precisaríamos para desenvolver a solução.
2. Usamos as principais funcionalidades da linguagem, como:
   - Alocação de memoria dinâmica: utilizada em praticamente todo o nosso código, para evitarmos desperdício de recursos.
   - Recursividade: utilizada nos menus de navegação do programa para manter um fluxo fluido e continuo, sem a necessidade de laços infinitos
   - Ponteiros: utilizada em praticamente todo o nosso código. Para nos referenciarmos a arquivos, parâmetros de funções, entre outros.
   - Manipulação de arquivos: essencial para a nossa solução, já que precisávamos de arquivos de texto simulando bancos de dados para guardar as informações dos usuários e funcionalidades.
   - Structs: para criarmos padrões de "objetos" e utilizarmos em diferentes partes do código.
   
## 🔗 Google Sites

O Google Site é utilizado como repositório geral das atividades da equipe.
- <a href="https://sites.google.com/cesar.school/plurii-clockin/home">
  <img src="https://img.shields.io/badge/Acessar%20Site%20-Google Sites-%2304D361">
</a>

## 🔗 Replit

O Replit foi utilizado como ambiente de desenvolvimento da solução da equipe.
- <a href="https://replit.com/@ADRIANALUCIA/MonitoramentoEducacional">
  <img src="https://img.shields.io/badge/Acessar%20Ambiente%20-Replit-%2304D361"></a>
- <a href="https://docs.google.com/spreadsheets/d/1Kosrgs8cgRyc4zcYgwSPcIUkc2J53D01c-LtiPMPYdw/edit?pli=1#gid=639311192">
  <img src="https://img.shields.io/badge/Acessar%20planilha de estrutura de dados%20-Google Sheets-%2304D361"></a>

## 🎨 Layout

O layout completo da aplicação está disponível no Figma:

<a href="https://www.figma.com/file/SZ1Lersblyaxq2SaeEEe3A/Projetos-2_PlurII?type=design&node-id=365-192&t=pHlf22VxVwWxgdN6-0">
  <img src="https://img.shields.io/badge/Acessar%20Layout%20-Figma-%2304D361">
</a>

## 📱 Telas

<p align="center">
  <img alt="tela-inicial" title="#plurii" src="./assets/Splashcreen.svg" width="200px">

  <img alt="tela-escolha-user" title="#plurii" src="./assets/EscolhaUser.svg" width="200px">
  
  <img alt="tela-login" title="#plurii" src="./assets/Login.svg" width="200px">
  
  <img alt="tela-home" title="#plurii" src="./assets/Home.svg" width="200px">
</p>

## ☕ Board e Backlog no Jira

- Utilizamos a metodologia ágil Scrum e o Design Thinking, junto ao quadro Kanban, para organizar e orientar o desenvolvimento da solução. A partir disso, criamos as histórias necessárias e formamos nosso board e backlog no Jira.

<p align="center">
  <img alt="board-jira" title="#plurii" src="./assets/board-sprint-concluida.jpeg">

  <img alt="backlog-jira" title="#plurii" src="./assets/backlog-jira.jpeg">
</p>

## 👨‍💻 Video do código no terminal

<a href="https://drive.google.com/file/d/1hn6XijUO6C08WXEY37tb73gQkQV3ROr6/view?usp=sharing">
  <img src="https://img.shields.io/badge/Acessar%20video do terminal%20-Google Drive-%2304D361">
</a>

# 🤝 Integrantes da equipe
<table>
  <tr>
    <td align="center"><img style="border-radius: 50%;" src="https://avatars.githubusercontent.com/u/108764670?v=4" width="100px;"/><br/><sub><b>Adriana Rodrigues</b></sub></a><br/></a></td>
    <td align="center"><img style="border-radius: 50%;" src="https://avatars.githubusercontent.com/u/108446826?v=4" width="100px;"/><br/><sub><b>Ana Beatriz Alves</b></sub></a><br/></a></td>
    <td align="center"><img style="border-radius: 50%;" src="./assets/ANA BEATRIZ ROCHA.png" width="100px;" alt=""/><br /><sub><b>Ana Beatriz Rocha </b></sub></a><br /></a></td>
    <td align="center"><img style="border-radius: 50%;" src="./assets/ANA LUIZA LIMA.jpeg" width="100px;" alt=""/><br/><sub><b>Ana Luiza Lima</b></sub></a><br/></a></td>
    <td align="center"><img style="border-radius: 50%;" src="https://avatars.githubusercontent.com/u/104402971?v=4" width="100px;"/><br/><sub><b>Cristina Matsunaga</b></sub></a><br /></a></td>
    <td align="center"><img style="border-radius: 50%;" src="https://avatars.githubusercontent.com/u/39159963?v=4" width="100px;"/><br /><sub><b>Francisco Luz</b></sub></a><br /></a></td>
    <td align="center"><img style="border-radius: 50%;" src="./assets/JORGE.jpeg" width="100px;" alt=""/><br /><sub><b>Jorge Herbster</b></sub></a><br/></a></td>
    <td align="center"><img style="border-radius: 50%;" src="./assets/LUCI.jpeg" width="100px;" alt=""/><br /><sub><b>Lucibelle Lemos</b></sub></a><br/></a></td>
    <td align="center"><img style="border-radius: 50%;" src="https://avatars.githubusercontent.com/u/112591325?v=4" width="100px;"/><br/><sub><b>Thiago Araújo</b></sub></a><br /></a></td>
  </tr>
</table>
