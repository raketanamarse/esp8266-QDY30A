# esp8266-QDY30A
esp8266 + QDY30A (sensor pressure)

esp8266 (lolin wemos d1 mini) ----> rs485 (Модуль MAX485) ----> QDY30A ( [Digital Pressure Sensor](https://aliexpress.ru/item/1005002355626150.html?sku_id=12000020268077913) )

В проекте используется датчик давления QDY30A
через интерфейс rs485 ([используется конвертер](https://aliexpress.ru/item/32848344535.html?sku_id=65155011742&spm=a2g0o.search.0.0.3f4b15cdODkTN7)) 

    wemos d1 mini |  D1 --- RO | Модуль MAX485 
                  |  D7 --- RE | 
                  |     \__ DE | 
                  |  D2 --- DI | 


НИКОГДА не спользуете gpio2, gpio0, gpio15 для эмуляции  SoftwareSerial --> так как напряжение на этих пинах отвечает за тип загрузки платы
 
![изображение](https://user-images.githubusercontent.com/104571006/185757983-ad783d9d-1677-49b4-88fd-dfd6af976ee0.png)

при прошивки отключать преобразователь rs485 НЕ нужно, если плата не прошиваеться проверяйте какие пины используються в коде

[калькуятор CRC16](https://crccalc.com/)
