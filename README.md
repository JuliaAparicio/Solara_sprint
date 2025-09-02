
## 📋 Instruções de Entrega
  ### Arquivo .py
 **Parte 1:**  
   - Exercícios iniciais com Individual Household Electric Power Consumption
     

 **Parte 2:**  
   - Exercicios adicionais no dataset inicial

 **Parte 3:**  
   - Novo dataset Appliances Energy Prediction

 **Parte 4:**  
   - Exercícios no Orange Data Mining  

---

## 📊 Informações sobre o Dataset 1:

- **Nome:** Individual Household Electric Power Consumption  
- **Fonte:** UCI Machine Learning Repository  
- **Local da coleta:** Sceaux, França (7 km ao sul de Paris)  
- **Período de coleta:** Dezembro de 2006 a Novembro de 2010 (47 meses)  
- **Frequência de amostragem:** 1 minuto  
- **Total de registros:** 2.075.259  
- **Formato do arquivo:** `household_power_consumption.txt` (separado por ponto e vírgula)  
- **Tamanho:** 126.8 MB  
- **Valores ausentes:** Cerca de 1,25% dos registros possuem dados faltantes

### 📌 Características do Dataset

- **Tipo de dados:** Multivariado, Série Temporal  
- **Área temática:** Física e Química  
- **Tarefas associadas:** Regressão, Agrupamento (Clustering)  
- **Tipo de variáveis:** Numéricas contínuas (real)

### 📋 Variáveis

| Nome da Variável        | Tipo        | Descrição                                                                 | Unidade        | Valores Faltantes |
|-------------------------|-------------|---------------------------------------------------------------------------|----------------|-------------------|
| `Date`                  | Data         | Data no formato `dd/mm/yyyy`                                              | —              | Não               |
| `Time`                  | Categórica   | Hora no formato `hh:mm:ss`                                                | —              | Não               |
| `Global_active_power`   | Contínua     | Potência ativa média por minuto                                           | kW             | Sim               |
| `Global_reactive_power` | Contínua     | Potência reativa média por minuto                                         | kW             | Sim               |
| `Voltage`               | Contínua     | Voltagem média por minuto                                                 | Volt           | Sim               |
| `Global_intensity`      | Contínua     | Corrente média por minuto                                                 | Ampère         | Sim               |
| `Sub_metering_1`        | Contínua     | Medição da cozinha (lava-louças, forno, micro-ondas)                      | Wh             | Sim               |
| `Sub_metering_2`        | Contínua     | Medição da lavanderia (máquina de lavar, secadora, geladeira, luz)       | Wh             | Sim               |
| `Sub_metering_3`        | Contínua     | Medição do aquecedor elétrico e ar-condicionado                           | Wh             | Sim               |

---


## 📊 Informações sobre o Dataset 2 

- **Nome:** Appliances Energy Prediction  
- **Fonte:** [GitHub - LuisM78](https://github.com/LuisM78/Appliances-energy-prediction-data)  
- **Publicação:** Energy and Buildings, Volume 140, 2017  
- **Período de coleta:** ~4,5 meses  
- **Frequência de amostragem:** 10 minutos  
- **Total de registros:** 19.735  
- **Total de variáveis:** 28  
- **Tamanho do arquivo:** 11.4 MB (`energydata_complete.csv`)  
- **Valores ausentes:** Não há valores faltantes

### 📌 Características

- **Tipo de dados:** Multivariado, Série Temporal  
- **Área temática:** Ciência da Computação  
- **Tarefa associada:** Regressão  
- **Tipo de variáveis:** Numéricas contínuas (real)

---

## 📋 Variáveis Principais

| Nome da Variável | Tipo       | Descrição                                               | Unidade |
|------------------|------------|----------------------------------------------------------|---------|
| `date`           | Data       | Data e hora no formato `YYYY-MM-DD HH:MM:SS`             | —       |
| `Appliances`     | Alvo       | Consumo de energia dos eletrodomésticos                 | Wh      |
| `lights`         | Feature    | Consumo de energia das luminárias                      | Wh      |
| `T1` a `T9`      | Feature    | Temperatura em diferentes cômodos da casa              | °C      |
| `RH_1` a `RH_9`  | Feature    | Umidade relativa em diferentes cômodos da casa         | %       |
| `To`             | Feature    | Temperatura externa (estação meteorológica)            | °C      |
| `Pressure`       | Feature    | Pressão atmosférica                                     | mm Hg   |
| `RH_out`         | Feature    | Umidade relativa externa                                | %       |
| `Wind speed`     | Feature    | Velocidade do vento                                     | m/s     |
| `Visibility`     | Feature    | Visibilidade                                             | km      |
| `Tdewpoint`      | Feature    | Ponto de orvalho                                         | °C      |
| `rv1`, `rv2`     | Feature    | Variáveis aleatórias para teste de modelos              | —       |

---




