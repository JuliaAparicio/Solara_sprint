import telebot
import unicodedata
import difflib

# === CONFIGURAÇÃO DO BOT DO TELEGRAM ===
import os
TOKEN = "SEU_TOKEN_AQUI"
bot = telebot.TeleBot(TOKEN)

# === FUNÇÕES DE NORMALIZAÇÃO E SIMILARIDADE ===
def normalizar_texto(texto):
    texto = texto.lower().strip()
    texto = unicodedata.normalize('NFKD', texto).encode('ASCII', 'ignore').decode('ASCII')
    return texto

def texto_parecido(texto, lista_referencia, corte=0.8):
    texto = normalizar_texto(texto)
    correspondencias = difflib.get_close_matches(texto, lista_referencia, n=1, cutoff=corte)
    return correspondencias[0] if correspondencias else None

# === MENSAGEM DE BOAS-VINDAS ===
@bot.message_handler(func=lambda msg: texto_parecido(msg.text, ['oi solara', 'começar']))
def boas_vindas(msg):
    bot.reply_to(msg, 'Olá, espero que o seu dia esteja sendo bom! Pode me perguntar algo sobre o clima ou energia.')

# === MENSAGEM SOBRE O TEMPO ===
@bot.message_handler(func=lambda msg: texto_parecido(msg.text, ['qual a previsão do tempo para amanhã']))
def previsao_tempo(msg):
    bot.reply_to(msg, '''🌤️ Previsão do Tempo para Amanhã

Amanhã o dia será de céu parcialmente nublado, com temperaturas entre 14°C e 21°C. A chance de chuva é baixa, e o clima deve se manter estável ao longo do dia.

Um cenário tranquilo, com variações suaves — perfeito para seguir a rotina com leveza.''')

# === MENSAGEM SOBRE ABASTECIMENTO ENERGÉTICO === 
@bot.message_handler(func=lambda msg: texto_parecido(msg.text, ['e como está o meu abastecimento energético']))
def abastecimento_hoje(msg):
    bot.reply_to(msg, '''Se sua casa pudesse falar, ela diria: “Hoje estou cheia de energia, pronta pra te servir com sol no coração e watts na tomada.”

As baterias estão 92% carregadas neste momento, garantindo autonomia mesmo durante a noite. Nenhum alerta foi registrado e o consumo está dentro da média habitual.

Tudo funcionando como esperado, caso algo mude eu mandarei um alerta para que possamos ver a melhor forma para solucionar o seu problema!''')

# === MENSAGEM SOBRE PREOCUPAÇÃO COM O ABASTECIMENTO DE AMANHÃ === 
@bot.message_handler(func=lambda msg: texto_parecido(msg.text, ['devo me preocupar com o meu abasteciomento energético de amanhã']))
def abastecimento_amanha(msg):
    bot.reply_to(msg, '''Tradução para o dia ☀️
Geladeira? Tranquila. 
Chuveiro elétrico? Pode usar sem culpa (mas com consciência). 
Ar-condicionado? Vai rodar com energia limpa. 
Bateria solar? Provavelmente carregada até o talo.

Não precisa se preocupar, caso algo mude estarei aqui para te avisar!✨''')

# === MENSAGEM DE ENCERRAMENTO === 
@bot.message_handler(func=lambda msg: texto_parecido(msg.text, ['combinado, obrigada!']))
def despedida(msg):
    bot.reply_to(msg, 'Estou aqui para te ajudar sempre que precisar, até breve!')

# === MANTÉM O BOT ATIVO ===
bot.infinity_polling()
