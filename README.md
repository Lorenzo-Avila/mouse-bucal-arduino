# 🖱️ Mouse Bucal — Tecnologia Assistiva com Arduino Pro Micro

> **TCC — Instituto Federal de Educação, Ciência e Tecnologia Farroupilha Campus São Borja — Técnico em Informática (2020)**  
> Dispositivo de interface humana (HID) que emula um mouse via joystick controlado pela boca, projetado para pessoas com deficiências motoras severas nos membros superiores.

---

## 📋 Sumário

- [Problema Resolvido](#-problema-resolvido)
- [Como Funciona](#-como-funciona)
- [Tecnologias e Componentes](#-tecnologias-e-componentes)
- [Estrutura do Repositório](#-estrutura-do-repositório)
- [Instalação e Montagem](#-instalação-e-montagem)
- [Configuração do Software](#-configuração-do-software)
- [Diagrama de Atores e Fluxo](#-diagrama-de-atores-e-fluxo)
- [Análise Técnica do Código](#-análise-técnica-do-código)
- [Modelo 3D](#-modelo-3d)
- [Sugestões de Melhorias](#-sugestões-de-melhorias)
- [Fundamentação Teórica](#-fundamentação-teórica)

---

## 🎯 Problema Resolvido

Pessoas com limitações motoras severas nos membros superiores como tetraplegia, distrofia muscular ou sequelas de AVC encontram barreiras significativas no uso de computadores convencionais. Este projeto oferece uma solução de **Tecnologia Assistiva (TA)** de baixo custo que permite controle completo do cursor por meio de movimentos da boca/cabeça, promovendo autonomia digital e inclusão social.

**Contexto:** A Declaração de Salamanca (1994) e as diretrizes brasileiras de inclusão exigem ferramentas adaptadas para que pessoas com deficiência possam participar plenamente de atividades educacionais e profissionais mediadas por computador.

---

## ⚙️ Como Funciona

```
[Usuário]
    │
    ▼ movimento da boca/mandíbula
[Joystick 3 eixos]  ──(A0, A2, D9)──►  [Arduino Pro Micro]
                                               │
                                         USB HID (nativo)
                                               │
                                               ▼
                                        [Computador — Driver-free]
                                        Cursor X/Y + Click esquerdo
```

1. O joystick é posicionado na boca do usuário via suporte impresso em 3D.  
2. Movimentos da mandíbula/língua deflectem o joystick nos eixos X e Y.  
3. O Arduino Pro Micro lê os valores analógicos (ADC 10-bit, 0–1023).  
4. A diferença do valor neutro (calibrado na inicialização) é mapeada em deslocamento do cursor.  
5. Pressionar o joystick (eixo Z) aciona o clique esquerdo do mouse.  
6. O computador reconhece o dispositivo automaticamente como mouse USB (sem drivers adicionais).

---

## 🔧 Tecnologias e Componentes

### Hardware

| Componente | Especificação | Função |
|---|---|---|
| **Arduino Pro Micro** | ATmega32U4, 5V/16MHz | MCU com USB HID nativo |
| **Módulo Joystick** | 3 eixos (X, Y, Z), potenciômetros 10kΩ | Sensor de movimento |
| **Cabo USB Micro-B** | Standard | Alimentação + dados |
| **Invólucro 3D** | PLA/ABS, STL binário (51.518 triângulos) | Suporte ergonômico bucal |
| **Parafusos/Fixadores** | M2/M3 | Montagem mecânica |

### Software / Ferramentas

| Ferramenta | Versão Recomendada | Uso |
|---|---|---|
| **Arduino IDE** | 2.x | Upload do firmware |
| **Biblioteca `Mouse.h`** | Built-in (Arduino AVR) | Emulação HID USB |
| **Fritzing** | 0.9.x | Esquemático do circuito (`.fzz`) |
| **Slicer 3D** (Cura/PrusaSlicer) | Qualquer | Impressão do modelo `.stl` |

---

## 📁 Estrutura do Repositório

| Pasta | Arquivo(s) | Descrição |
|---|---|---|
| `firmware/` | `Emulador_Mouse.ino` | Código principal — lógica do mouse HID |
| `hardware/` | `Joystick_and_arduino.fzz` | Esquemático completo no Fritzing |
| | `esquematico_prototipo.JPG` | Diagrama de conexões (imagem) |
| | `esquema_de_funcionamento.png` | Fluxo do sistema |
| | `Diagrama_de_Circuitos.JPG` | Foto do circuito montado |
| `3dmodels[](url)/` | `Modelo3d_projeto.stl` | Invólucro bucal — STL binário (~2,5 MB, 51.518 triângulos) |
| `docs/` | `Ata_de_Defesa_Final_do_Trabalho_de_Conclusão_de_Curso.docx` | Ata de Defesa Final do Trabalho de Conclusão de Curso |
| `Relatório_de_Trabalho_de_Conclusao_de_curso.docx` | Relatório técnico  referente ao Trabalho de Conclusão de Curso |
| | `Atores_do_Sistema.jpg` | Diagrama de atores do sistema |
| `fotos_prototipo/` | `impressao_bucal_1.jpg` · `impressao_bucal_2.jpg`  | Vistas externas da impressão do bucal protótipo finalizado |
| | `protitpo_finalizado_sem_involtorio.jpg` · `prototipo_finalizado_com_involtorio_visao_externa.jpg` | Comparação sem/com invólucro |
| | `prototipo_finalizado_com_involtorio_parte_interna.jpg` | Eletrônica interna montada |
| | `Ligacoes_1.jpg` · `Ligacoes_2.jpg` · `Ligacoes_3.jpg` | Fiação e conexões detalhadas |
| | `arduino_pro_micro.jpg` · `Joystick.jpg` | Componentes individuais |

**Como abrir cada tipo de arquivo:**

| Extensão | Ferramenta |
|---|---|
| `.ino` | Arduino IDE 2.x |
| `.fzz` | Fritzing 0.9.x |
| `.stl` | Cura / PrusaSlicer / Blender |
| `.docx` | Word / LibreOffice Writer |
| `.jpg` / `.png` | Qualquer visualizador de imagens |

---

## 🔨 Instalação e Montagem

### Pré-requisitos

- Arduino IDE 2.x instalado
- Impressora 3D (ou serviço de impressão) para o invólucro
- Filamento PLA (recomendado para contato bucal: **PETG food-safe** ou revestimento com verniz atóxico)

### Passo 1 — Impressão 3D

1. Abra o arquivo `3d-models/Modelo 3d TCC (1).stl` no seu slicer.
2. Configurações sugeridas:
   - Preenchimento: **30–40%** (honeycomb)
   - Altura de camada: **0.2mm**
   - Suportes: Ativados (verifique as abas de encaixe do joystick)
3. Imprima e lixe as bordas que terão contato com a boca.

### Passo 2 — Conexões Elétricas

| Pino Joystick | Pino Arduino Pro Micro |
|---|---|
| VCC | VCC (5V) |
| GND | GND |
| VRX (eixo horizontal) | A0 |
| VRY (eixo vertical) | A2 |
| SW (botão/click) | D9 |

> **Atenção:** O pino D9 usa `INPUT_PULLUP` interno — leitura `LOW` indica botão pressionado.

### Passo 3 — Upload do Firmware

1. Abra `firmware/Emulador_Mouse.ino` na Arduino IDE.
2. Selecione: **Ferramentas → Placa → Arduino AVR → Arduino Leonardo** (compatível com Pro Micro ATmega32U4).
3. Selecione a porta COM correta.
4. Clique em **Upload**.
5. Na primeira inicialização, mantenha o joystick na **posição neutra** por 1 segundo — o código calibra o ponto zero automaticamente.

### Passo 4 — Montagem Mecânica

1. Encaixe o módulo joystick no suporte impresso.
2. Direcione os cabos pelo canal interno do invólucro.
3. Prenda o Arduino Pro Micro no compartimento traseiro.
4. Conecte o cabo USB ao computador — nenhum driver adicional necessário.

---

## 💻 Configuração do Software

### Ajuste de Sensibilidade

No arquivo `.ino`, a constante `sensitivity` controla a velocidade do cursor:

```cpp
const int sensitivity = 200; // ← altere este valor
```

| Valor | Comportamento |
|---|---|
| `50–100` | Cursor **muito rápido** — para usuários com controle preciso |
| `200` | **Padrão** (configuração original) |
| `400–600` | Cursor **lento** — ideal para tremores ou movimentos involuntários |

---

## 📐 Diagrama de Atores e Fluxo

**Atores do Sistema:**

- **Usuário** — pessoa com deficiência motora que utiliza o dispositivo bucal
- **Supervisor** — responsável pela instalação, posicionamento e verificação do protótipo

**Fluxo de Operação:**

```
Supervisor conecta USB → Sistema inicializa (1s calibração)
        │
        ├─ Sensores OK? ──NÃO──► Sistema reinicia
        │
        SIM
        │
        ▼
Monitoramento contínuo do joystick
        │
        ├─ Movimento eixo X → Mouse.move(Δx, 0, 0)
        ├─ Movimento eixo Y → Mouse.move(0, Δy, 0)
        └─ Botão pressionado → Mouse.press/release (LEFT)
```

---

## 🔬 Análise Técnica do Código

### Lógica Central

```cpp
// Leitura diferencial — desconta o ponto zero calibrado
vertValue = analogRead(vertPin) - vertZero;
horzValue = analogRead(horzPin) - horzZero;

// Movimento proporcional dividido pela sensibilidade
if (vertValue != 0) Mouse.move(0, vertValue / sensitivity, 0);
if (horzValue != 0) Mouse.move(horzValue / sensitivity, 0, 0);

// Clique com debounce via flag
if (digitalRead(selPin) == 0 && !mouseClickFlag) {
    mouseClickFlag = 1;
    Mouse.press(MOUSE_LEFT);
} else if (digitalRead(selPin) && mouseClickFlag) {
    mouseClickFlag = 0;
    Mouse.release(MOUSE_LEFT);
}
```

### Pontos Críticos Identificados

| # | Problema | Impacto |
|---|---|---|
| 1 | **Sem zona morta (deadzone)** | Qualquer ruído no ADC move o cursor continuamente |
| 2 | **`Serial.begin(9600)` ativo em produção** | Consome memória e ciclos de CPU desnecessariamente |
| 3 | **Comentários com eixos X/Y trocados** | Dificulta manutenção futura |
| 4 | **`INPUT` sem `PULLUP` no `selPin`** | Leituras flutuantes quando o botão não está pressionado |
| 5 | **Sem suporte a clique direito** | Limita usabilidade (sem acesso a menus contextuais) |
| 6 | **Calibração apenas no boot** | Deriva térmica dos potenciômetros não é compensada |

---

## 🖨️ Modelo 3D

- **Formato:** STL Binário
- **Complexidade:** 51.518 triângulos
- **Tamanho:** ~2,5 MB
- **Finalidade:** Invólucro ergonômico que acopla o módulo joystick em posição bucal
- **Integração com eletrônica:** Cavidades internas para passagem de cabos; compartimento traseiro para o Arduino Pro Micro; encaixe frontal para o joystick na posição bocal

> ⚠️ **Recomendação de material:** Para uso em contato com a boca, imprimir em **PETG food-safe** ou aplicar **revestimento atóxico** (verniz epóxi alimentar) sobre PLA.

### 🟢 Evoluções Futuras

**8. Sopro/Sucção como Botão** — sensor de pressão (BMP280) para ação de clique sem usar o joystick como botão

**9. Modo de Acessibilidade Configurável** — potenciômetro externo para ajuste de sensibilidade em tempo real sem reprogramar

**10. BLE/Wireless** — substituir Arduino Pro Micro por **Seeed XIAO nRF52840** para versão sem fio (Bluetooth HID)

**11. Controle por Inclinação (IMU)** — adicionar MPU-6050 para controle por movimento de cabeça, dispensando o joystick

---

## 📚 Fundamentação Teórica

- **Declaração de Salamanca (UNESCO, 1994):** Estabelece diretrizes mundiais para educação inclusiva, motivando o desenvolvimento de ferramentas assistivas.
- **Tecnologia Assistiva (TA):** Campo interdisciplinar que cria produtos e serviços para promover funcionalidade e autonomia de pessoas com deficiência.
- **USB HID (Human Interface Device):** Protocolo USB que permite que microcontroladores se comuniquem com computadores como periféricos de entrada sem drivers adicionais — viabilizado pelo chip ATmega32U4 do Arduino Pro Micro.
- **ADC (Analog-to-Digital Converter):** Converte o sinal analógico dos potenciômetros do joystick (0–5V) em valores digitais de 10 bits (0–1023), mapeados em deslocamento do cursor.

---

## 📄 Licença

Projeto acadêmico de código aberto. Uso livre para fins educacionais e de pesquisa em Tecnologia Assistiva.

---

*Desenvolvido como Trabalho de Conclusão de Curso — Técnico em Informática, 2020.*
