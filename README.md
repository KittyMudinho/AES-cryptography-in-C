<html>
  <body>
    <h1>AES Cryptography in C (English)
    <p>
      <h3>I'm going to explain the code in English and in Portuguese.</h3>
    </p>
      <p>
      <h3>This code is about AES Cryptography, in the its simplest form.</h3>
        <h3>Firstly I'll introduce all the concepts:</h3>
        <h3>S-Box: it's a big array we use in SubBytes step, you're going to see it;</h3>
        <h3>SubBytes: step we identify the matching hexadecimal numbers from the original array to S-Box;</h3>
        <h3>ShiftRows: step we move the line of the array according to its position, for example, line 0 we make 0 move, line 1 one move...</h3>
        <h3>MixCollumns: XOR operation between the result ShiftRows array and a defined array;</h3>
        <h3>AddRoundKey: XOR operation between the result MixCollumns array and a defined array.</h3>
    </p>
      <p>
      <h1>AES Encryption Procces</h1>
        <h1>S-Box</h1>
        <h3>It can be calculated, but I took one already done:</h3>
        ![image](https://github.com/user-attachments/assets/a7726295-1b2f-481e-aec6-cb1c6fdd649d)
        <h1>SubBytes</h1>
        <h3>Take the original message in hexadecimal, I used UTF-8 table to do it, the easiest way is take the message and printf with %x, example:</h3>
        <h3>unsigned char message[5]={"good"};</h3>
        <h3>for(int i=0;i<5;i++){</h3>
          <h3>printf("%x ",message[i];</h3>
          <h3>}</h3>
          <h3>Searching on google you can find a way to take the value of that printf into a variable, it's your decision.</h3>
          <h3>The code just take the hexadecimal value and "points" to its place on S-Box, for example: a00=5F is on line 5 column F in S-Box and it's 8c, then a00 in SubBytes Array is 8c</h3>
          <h1>ShiftRows</h1> 
          <h3>step we move the line of the array according to its position, for example, line 0 we make 0 move, line 1 one move...</h3>
          <h1>MixCollumns</h1>
          <h3>It's quite hard/boring to do on paper, but let's try to understand...</h3>
          <h3>It's a matricial multiplication between a defined array and each collum of the ShiftRows array, but we don't add the vallues, instead, we make a XOR operation, and we don't mutiple, instead, we make rijndael's field operation, let's do it step by step:</h3>
          <h3>Let's take 7F, it's 1111011 in binary, now, we gotta transform it into a polynomial.</h3>
          <h3>1111011</h3>
          <h3>1x^6+1x^5+1x^4+1x^3+0x^2+1x^1+1x^0</h3>
          <h3>x^6+x^5+x^4+x^3+x+1</h3>
          <h3>The "formula" is: ajX^(j-1), j=position, aj=elemente in the position j, j starts as 0.</h3>
          <h3>Nice... now we have to make the MixCollumns operation:</h3>
          <h3>Let's take (1)(3F7E)</h3>
          <h3>(1)(0011111101111110)</h3>
          <h3>(1)(x^13+x^12+x^11+x^10+x^9+x^8+x^6+x^5+x^4+x^3+x^2+x)</h3>
          <h3>(x^13+x^12+x^11+x^10+x^9+x^8+x^6+x^5+x^4+x^3+x^2+x)</h3>
          <h3>11111101111110</h3>
          <h3>The last step is a modular operation, using (x^8+x^4+x^3+x+1), it's a "standard" polynomial:</h3>
          <h3>11111101111110mod100011011:</h3>
          ![image](https://github.com/user-attachments/assets/a59d1d10-fb35-4786-b3e7-56797bc04a9b)
          <h1>AddRoundKey</h1>
          <h3>Similar to MixCollumns, but there's a key we make XOR operation with each element of MixCollumns array</h3>
          <h2>You can do all procces as much as you want to</h2>
        </p>
      <p>
      <h1>AES Desencryption Procces</h1>
        <h1>R-S-Box</h1>
        <h3>It can be calculated, but I took one already done:</h3>
        ![image](https://github.com/user-attachments/assets/854d04e0-8adb-4a82-9ee8-4d454c16670b)
        <h1>InvAddRoundKey</h1>
        <h3>It's simple, just do the XOR operation between the addRoundKey array and its key</h3>
        <h1>InvMixCollumns</h1>
        <h3>I confess: it's not really correct, but I tried so hard and got absolutely nothing, then I had to do some trick... I got the MixCollumns array and made XOR operation with the ShiftRows to get the key to obtain the ShiftCollumns array, because the reverse operation of XOR is XOR, it's worked, not as it might to, but worked...</h3>
          <h1>InvShiftRows</h1>
          <h3>Just reverse what you've done on ShiftRows</h3>
          <h1>InvSubBytes</h1>
          <h3>Same of SubBytes but now using the R-S-Box.</h3>
        </p>
        <p>
          <h1>That's it, the simplest way to do the AES Encryption, at least the simplest I can do...</h1>
        </p>
          <h1>AES criptografia em C (Português)
      <h3>Esse código é sobre criptografia AES, na forma mais simples possível.</h3>
        <h3>Primeiramente, vou introduzir os conceitos:</h3>
        <h3>S-Box: É uma grande matriz que usamos em SubBytes, você verá como</h3>
        <h3>SubBytes: etapa que identificamos os números hexadecimais correspondentes da matriz original para a S-Box;</h3>
        <h3>ShiftRows: etapa que movemos uma linha da matriz de acordo com sua posição, por exemplo, linha 0 fazemos 0 movimentos, linha 1 um movimento...</h3>
        <h3>MixCollumns: operação XOR entre a matriz resultante do ShiftRows e uma matriz fixa/definida;</h3>
        <h3>AddRoundKey: operação XOR entre a matriz resultante do MixCollumns e uma matriz fixa/definida.</h3>
    </p>
      <p>
      <h1>Processo de encriptação AES</h1>
        <h1>S-Box</h1>
        <h3>Pode ser calculada, mas eu peguei uma pronta:</h3>
        ![image](https://github.com/user-attachments/assets/a7726295-1b2f-481e-aec6-cb1c6fdd649d)
        <h1>SubBytes</h1>
        <h3>Pega a mensagem original em hexadecimal, eu usei a tabela UTF-8, a maneira mais fácil é usando o printf com %x, exemplo:</h3>
        <h3>unsigned char message[5]={"good"};</h3>
        <h3>for(int i=0;i<5;i++){</h3>
          <h3>printf("%x ",message[i];</h3>
          <h3>}</h3>
          <h3>Pesquisando no google você consegue achar uma maneira de pegar o valor do printf dentro de uma variável, a decisão é sua.</h3>
          <h3>O código pega o valor hexadecimal e "aponta" para sua poisção na S-Box, por exemplo: a00=5F está na linha 5 coluna F na S-Box e isso é 8c, portanto, a00 na matriz do SubBytes é 8c</h3>
          <h1>ShiftRows</h1> 
          <h3>etapa que movemos uma linha da matriz de acordo com sua posição, por exemplo, linha 0 fazemos 0 movimentos, linha 1 um movimento...</h3>
          <h1>MixCollumns</h1>
          <h3>É meio difícil/chato de fazer no papel, mas vamos tentar entender...</h3>
          <h3>É um produto matricial entre uma matriz definida/fixa com cada coluna da matriz do ShiftRows, mas nós não somamos os valores, fazemos uma operação XOR, como está na foto abaixo:</h3>
          ![image](https://github.com/user-attachments/assets/88e565c3-5a7a-4c50-9a9d-4a5bdbcf3cb4)
          <h1>AddRoundKey</h1>
          <h3>Similar com o MixCollumns, mas aqui a temos uma chave que fazemos uma XOR com cada elemento da matriz do MixCollumns.</h3>
          <h2>Você pode fazer o processo quantas vezes quiser.</h2>
        </p>
      <p>
      <h1>Processo de desencriptação AES</h1>
        <h1>R-S-Box</h1>
        <h3>Pode ser calculada, mas eu peguei uma pronta:</h3>
        ![image](https://github.com/user-attachments/assets/854d04e0-8adb-4a82-9ee8-4d454c16670b)
        <h1>InvAddRoundKey</h1>
        <h3>É simples, só fazer uma XOR entre a matriz do AddRoundKey e sua chave.</h3>
        <h1>InvMixCollumns</h1>
        <h3>Confesso que não está realmente certo, mas eu tentei de todas as formas e obtive nada, então tive que fazer uma maracutaia... Peguei a matriz do MixCollumns e fiz uma XOR com a do ShiftRows, obtendo uma chave que será usada para reverter  MixCollumns, funcionou, não como deveria, mas funcionou...</h3>
          <h1>InvShiftRows</h1>
          <h3>Só inverte o que foi feito no ShiftRows</h3>
          <h1>InvSubBytes</h1>
          <h3>Mesma coisa do SubBytes, mas com a R-S-Box</h3>
        </p>
        <p>
          <h1>É isso, a maneira mais simples de fazer uma encriptação AES, pelo menos o mais simples que eu consegui fazer...</h1>
        </p>
  </body>
</html>
