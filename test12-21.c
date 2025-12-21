#include <stdio.h>

int main() {
    double num1, num2, result;
    char op;
    char continueFlag;

    printf("========== 简易计算器 ==========\n");
    printf("支持运算：+ - * / %%（取模，仅整数）\n");

    while (1) {
        // 输入第一个数
        printf("\n请输入第一个数：");
        while (scanf("%lf", &num1) != 1) {
            while (getchar() != '\n');
            printf("输入无效，请输入数字：");
        }

        // 输入运算符
        printf("请输入运算符：");
        scanf(" %c", &op); // 空格避免读取上一行的换行符

        // 输入第二个数
        printf("请输入第二个数：");
        while (scanf("%lf", &num2) != 1) {
            while (getchar() != '\n');
            printf("输入无效，请输入数字：");
        }

        // 根据运算符计算
        switch (op) {
        case '+':
            result = num1 + num2;
            printf("结果：%.2lf %c %.2lf = %.2lf\n", num1, op, num2, result);
            break;
        case '-':
            result = num1 - num2;
            printf("结果：%.2lf %c %.2lf = %.2lf\n", num1, op, num2, result);
            break;
        case '*':
            result = num1 * num2;
            printf("结果：%.2lf %c %.2lf = %.2lf\n", num1, op, num2, result);
            break;
        case '/':
            if (num2 == 0) {
                printf("错误：除数不能为0！\n");
            }
            else {
                result = num1 / num2;
                printf("结果：%.2lf %c %.2lf = %.2lf\n", num1, op, num2, result);
            }
            break;
        case '%':
            // 取模仅支持整数，强制转换
            if ((int)num2 == 0) {
                printf("错误：除数不能为0！\n");
            }
            else {
                result = (int)num1 % (int)num2;
                printf("结果：%d %c %d = %d\n", (int)num1, op, (int)num2, (int)result);
            }
            break;
        default:
            printf("错误：无效的运算符！\n");
            break;
        }

        // 询问是否继续
        printf("是否继续计算？(y/n)：");
        scanf(" %c", &continueFlag);
        if (continueFlag != 'y' && continueFlag != 'Y') {
            printf("计算器已退出！\n");
            break;
        }
    }

    return 0;
}