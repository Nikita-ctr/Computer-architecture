#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/io.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your name");
MODULE_DESCRIPTION("Simple Linux module with Assembler");
MODULE_VERSION("0.1");

int readPort(int reg) {
    outb_p(reg, 0x70);
                                // Записываем адрес порта ввода-вывода для чтения
    return inb(0x71);           // Возвращаем значение, считанное из порта
}

int init_module(void) {
    printk(KERN_INFO
    "ASMModule loaded.\n");

    char value;                  // Объявляем переменную для хранения значения, считанного из порта
    asm("cli");                  // Отключаем прерывания процессора
    value = readPort(0x14);       // Считываем значение из порта с адресом 0x14
    asm("sti");                  // Включаем прерывания процессора

    printk(KERN_INFO
    "ASMModule: %x\n", value);

    if (value & 1) {
        printk(KERN_ALERT "присутствует дисковод гибких дисков \n");
    } else {
        printk(KERN_ALERT "отсутствует дисковод гибких дисков \n");
    }

    if (value & 2) {
        printk(KERN_ALERT "присутствует блок процессора для операций с плавающей точкой \n");
    } else {
        printk(KERN_ALERT "отсутсвует блок процессора для операций с плавающей точкой  \n");
    }

    if (value & 4) {
        printk(KERN_ALERT "есть клавиатура \n");
    } else {
        printk(KERN_ALERT "отсутствует клавиатура \n");
    }   }

    if (value & 4) {
        printk(KERN_ALERT "есть клавиатура \n");
    } else {
        printk(KERN_ALERT "отсутствует клавиатура \n");
    }

    if (value & 8) {
        printk(KERN_ALERT "есть дисплей \n");
    } else {
        printk(KERN_ALERT "отсутствует дисплей \n");
    }

    if (value & 16) {
        printk(KERN_ALERT "основной видеоадаптер: · 00 - EGA или VGA \n");
    }
// проверяет количество дисководов гибких дисков, представленных битами 6 и 7 в числе "value".
// Он использует операцию "AND" (&) с маской "192" (11000000 в двоичном виде),
// чтобы получить значения битов 6 и 7, а затем сравнивает их со значениями 0, 64, 128 и 192,
// соответствующими количествам дисководов 1, 2, 3 и 4 соответственно. Если значение не соответствует ни одному из этих случаев,
// он выдает сообщение "количество дисководов гибких дисков: неизвестное значение".
    if ((value & 192) == 0) {
        printk(KERN_ALERT
        "один дисковод гибких дисков \n");
    } else if ((value & 192) == 64) {
        printk(KERN_ALERT
        "два дисковода гибких дисков \n");
    } else if ((value & 192) == 128) {
        printk(KERN_ALERT
        "три дисковода гибких дисков \n");
    } else if ((value & 192) == 192) {
        printk(KERN_ALERT
        "четыре дисковода гибких дисков \n");
    } else {
        printk(KERN_ALERT
        "количество дисководов гибких дисков: неизвестное значение \n");
    }

    return 0;
}
void cleanup_module(void)
{
    printk(KERN_ALERT "ASMModule unloaded.\n");
}
