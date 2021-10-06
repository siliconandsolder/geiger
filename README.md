# Geiger
This is a simple geiger counter that I made back in 2019-2020 using an Soviet STS-5 geiger tube and an Arduino Nano. 

The red button changes the interval at which the geiger counter calculates CPM and micro-sieverts.

## Wiring Diagram
<img src="./img/geiger_small_bb.png" target="_blank" alt="drawing" width="500"/>

### List of Parts
<table>

  <thead>
   <tr>
    <th>Label</th>
    <th>Part Type</th>
    <th>Properties</th>
    </tr>
  </thead>
  <tbody>
  <tr>
    <td>N/A</td>
    <td>Geiger tube</td>
    <td>STS-5 (or SBM-20) tubes are cheap and ubiquitous</td>
  </tr>
  <tr>
    <td>N/A</td>
    <td>High Voltage DC-DC Boost Converter</td>
    <td>Needs to increase voltage to at least 300V</td>
  </tr>
  <tr>
    <td>C3</td>
    <td>Electrolytic Capacitor</td>
    <td class="props">capacitance 1μF; package 0405 [SMD, electrolytic]; voltage 6.3V</td>
</tr><tr>
    <td>C4</td>
    <td>Ceramic Capacitor</td>
    <td class="props">capacitance 100nF; package 100 mil [THT, multilayer]; voltage 6.3V</td>
</tr><tr>
    <td>C5</td>
    <td>Ceramic Capacitor</td>
    <td class="props">capacitance 22pF; package 100 mil [THT, multilayer]; voltage 6.3V</td>
</tr><tr>
    <td>C6</td>
    <td>Electrolytic Capacitor</td>
    <td class="props">capacitance 220µF; package 100 mil [THT, electrolytic]; voltage 6.3V</td>
</tr><tr>
    <td>C7</td>
    <td>Electrolytic Capacitor</td>
    <td class="props">capacitance 1μF; package 0405 [SMD, electrolytic]; voltage 6.3V</td>
</tr><tr>
    <td>C8</td>
    <td>Ceramic Capacitor</td>
    <td class="props">capacitance 100nF; package 200 mil [THT, multilayer]; voltage 6.3V</td>
</tr><tr>
    <td>LCM1602 IIC1</td>
    <td>LCM1602 IIC</td>
    <td class="props">chip label LCM1602 IIC; variant variant 2; package DIP (Dual Inline) [THT]; editable pin labels false; pins 22; part # LCM1602 IIC</td>
</tr><tr>
    <td>Part1</td>
    <td>Arduino Nano (Rev3.0)</td>
    <td class="props">type Arduino Nano (3.0)</td>
</tr><tr>
    <td>Part7</td>
    <td>Lithium Ion Cylindrical Battery 3.7v 2200mAh</td>
    <td class="props">variant 2200mAh; part # 1781</td>
</tr><tr>
    <td>Part8</td>
    <td>PowerBoost 500 Basic</td>
    <td class="props">variant 500; output connector Screw terminal; input connector JST</td>
</tr><tr>
    <td>Part9</td>
    <td>Micro Lipo Charger</td>
    <td class="props">variant variant 1</td>
</tr><tr>
    <td>proto1</td>
    <td>Adafruit PermaProto 1/2 Board</td>
    <td class="props">size 1/2</td>
</tr><tr>
    <td>proto2</td>
    <td>Adafruit PermaProto 1/4 Board</td>
    <td class="props">variant variant 1; size 1/4</td>
</tr><tr>
    <td>Q1</td>
    <td>NPN-Transistor</td>
    <td class="props">package SOT-23 [SMD]; type NPN</td>
</tr><tr>
    <td>Q2</td>
    <td>NPN-Transistor</td>
    <td class="props">package SOT-23 [SMD]; type NPN</td>
</tr><tr>
    <td>Q3</td>
    <td>NPN-Transistor</td>
    <td class="props">package SOT-23 [SMD]; type NPN</td>
</tr><tr>
    <td>R2</td>
    <td>10kΩ Resistor</td>
    <td class="props">tolerance ±5%; pin spacing 400 mil; package THT; bands 4; resistance 10kΩ</td>
</tr><tr>
    <td>R7</td>
    <td>330Ω Resistor</td>
    <td class="props">tolerance ±5%; pin spacing 400 mil; package THT; bands 4; resistance 330Ω</td>
</tr><tr>
    <td>R8</td>
    <td>1MΩ Resistor</td>
    <td class="props">tolerance ±5%; pin spacing 400 mil; package THT; bands 4; resistance 1MΩ</td>
</tr><tr>
    <td>R9</td>
    <td>10kΩ Resistor</td>
    <td class="props">tolerance ±5%; pin spacing 400 mil; package THT; bands 4; resistance 10kΩ</td>
</tr><tr>
    <td>R10</td>
    <td>5.1MΩ Resistor</td>
    <td class="props">tolerance ±5%; pin spacing 400 mil; package THT; bands 4; resistance 5.1MΩ</td>
</tr><tr>
    <td>R11</td>
    <td>1kΩ Resistor</td>
    <td class="props">tolerance ±5%; pin spacing 400 mil; package THT; bands 5; resistance 1kΩ</td>
</tr><tr>
    <td>R12</td>
    <td>110Ω Resistor</td>
    <td class="props">tolerance ±5%; pin spacing 400 mil; package THT; bands 5; resistance 110Ω</td>
</tr><tr>
    <td>S2</td>
    <td>Toggle Switch</td>
    <td class="props">package THT; switching circuit SPDT</td>
</tr><tr>
    <td>S3</td>
    <td>Round Pushbutton</td>
    <td class="props">default state Normally Open; switching circuit SPST</td>
</tr><tr>
    <td>SP1</td>
    <td>SPEAKER</td>
    <td class="props">package pcb_mount_speaker</td>
</tr><tr>
    <td>U2</td>
    <td>555 Timer</td>
    <td class="props">package DIP8 [THT]</td>
</tr><tr>
    <td>U3</td>
    <td>LCD-16X2</td>
    <td class="props">characters 16x2; variant silk; package lcd-16x2</td>
</tr><tr>
    <td>U4</td>
    <td>LM386</td>
    <td class="props">package dip08; chip lm386</td>
</tr>
  </tbody>
</table>

## Images
<img src="./img/IMG_20200224_225859.jpg" alt="drawing" width="400"/> <img src="./img/IMG_20200224_230338.jpg" alt="drawing" width="400"/>
