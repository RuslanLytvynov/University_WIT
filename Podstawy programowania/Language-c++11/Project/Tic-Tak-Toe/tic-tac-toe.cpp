#include <iostream>
char board[9] = {};              //Чтобы отобразить ход(ввод)пользователя на доске. Доска будит состоять из 9-и однобуквенных стрингов char

//=============================функция clearscreen ===========================================================================================================================================================================================================================================================================================================================

void clearscreen()               // очищает окно консоли, функция clearscreen ни чего не возвращае.
{
    for(int i = 0; i<100; i++)  //цикл for(int i = 0;  i<100;  i++) который отсчитывает от 0 до 100 и при каждом повторении цикла выводит на экран std::cout<<std::endl; новую строчку
    {
        std::cout<<std::endl;//выводит на экран std::cout<<std::endl; новую строчку
    }
}

//=============================функция clearboard===========================================================================================================================================================================================================================================================================================================================

void clearboard()            //эта функция очищает доску и ни чего не возвращает
{
    for(int i = 0; i<9; i++) //циклfor(int i = 0;  i<9;  i++)) который в цикле проходит по всем 9-и ячейкам на доске. board[i] поставит туда  пустышку = '-‘. Это возвращает доску в своё изначальное состояние.
    {
        board[i] = '-';  //board[i] поставит туда  пустышку = '-‘. Это возвращает доску в своё изначальное состояние.
    }

}

//==================================функция bool has_wonQ(char player)======================================================================================================================================================================================================================================================================================================================

bool has_wonQ(char player)                                     //функция bool has_wonQ(char player)которая проверяет когда игра закончилась. Функция has_wonQ  возвращает bool(правда или ложь, т.е. bool это переменная с двумя состояниями либо 0(ноль) если состояние ложь и либо 1(единица) если состояние правда)
{
    int wins[][3] = {{0,1,2}, {3,4,5}, {6,7,8}, {0,3,6}, {1,4,7},//двухмерный массив wins[8][3](8 по 3) в котором перечисляются все выигрышные варианты
        {2,5,8}, {0,4,8}, {2,4,6}
    };
//Этими циклами проверяется если у одного из игроков есть фишки на всех трёх местах из какой-нибудь из тройки. К примеру если один из игроков первым поставил крестики или нолики в клетках 1, 2, 3 (т.к. переменные отсчитываются с 0(ноля) тогда эквивалент клеток 1, 2, 3  в окне консоли в коде {0,1,2} ) то он выиграл.
//Грубо говоря цикл  for(int i = 0; i<8; i++)проверяет массив[8], а цикл  for(int j = 0; j<3; j++) проверяет массив [3]
    for(int i = 0; i<8; i++)     //цикл for который повторяется 8 раз (int i = 0; i<8; i++)
    {
        int count = 0;          //переменнаяint счётчикcount и задаётся ей значение =0. Грубо говоря цикл  for(int i = 0; i<8; i++)проверяет массив[8], а цикл  for(int j = 0; j<3; j++) проверяет массив [3]
        for(int j = 0; j<3; j++) //в этом цикле запускается ещё цикл for который повторяется 3 раза (int j = 0; j<3; j++)
        {
            if(board[wins[i][j]] == player)//Ifесли(на boardдоске на квадратике который задан в массиве[wins]по элементу[i] и [j] будит ровняться  player (проверяемого X или О (char player))
                count++;//Если на этом месте  в массиве доска стоит X то увеличивается count на единицу ++.
        }
        if(count == 3) //Ifесли(счётчикcount  ровняется== 3) т.е. к примеру проходится троечка {0,1,2} и все три ровняются крестику(Х) или нолику(О) то возвращаетсяreturn
        {
            return true;//правдаtrue(он выиграл)
        }
    }
    return false;    //а если это не произошло то возвращаетсяreturn ложьfalse(он не выиграл)
}

//===================================функция void print_board============================================================================================================================================================================================================================================================

void print_board(std::string indent) //функция void print_board(){ … } которая будит выводить  доску на экран
{
    std::cout <<"Game board\n";        //Выводится на экран заголовок Game board
    std::cout<<indent<<"-"<<board[6]<<"-|-"<<board[7]<<"-|-"<<board[8]<<"- \n";//Выводится пустая доска с заголовком “Game board” (игровое поле)
    std::cout<<indent<<"-"<<board[3]<<"-|-"<<board[4]<<"-|-"<<board[5]<<"- \n";// в которой и будут отображаться X или О
    std::cout<<indent<<"-"<<board[0]<<"-|-"<<board[1]<<"-|-"<<board[2]<<"- \n";//Заменяется переменная стринг (-) на переменную board[] с номером клетки, т.к.  переменные начинаются с нуля, то  вместо 1 пишется 0, вместо 2 пишется 1 и т.д.
}

//================================функция get_move=================================================================================================================================================================================================================================================================

int get_move() // Создаётся функция “get_move()“(Получить ввод пользователя)
{
    std::cout<<"\nMenu hodov: \n";     // С помощью std::cout  в окно выводится  заголовок Menu hodov:
    std::cout<<"-7-|-8-|-9-" << std::endl;// и номирацию ячеек  "-7-|-8-|-9-"  и т.д.
    std::cout<<"-4-|-5-|-6-" << std::endl;//Строки заканчиваются операторами  \n(оператор перехода на новую строчку) и endl  в конце строк (;)
    std::cout<<"-1-|-2-|-3-" << std::endl;//
    std::cout<<"\n";                      //Пропуск строки

    print_board("");//в скобках пишется пустой стринг (два двоеточие)
    std::cout << "\nVvod chisla: ";//Выводится сообщение Vvod chisla: объектом cout


    int move;// Что бы получить вход пользователя создаётся переменная move
    std::cin >> move;//Просим что бы пользователь ввёл эту переменную (число)
    while(move > 9 || move < 1 || board[move-1]!= '-') //Цикл  while  проверяет вход  который дал пользователь больше 9  (move > 9) или (|| ) вход меньше  1 (move < 1 )
    {
        std::cout<<"Vvedite chislo ot (1 do 9):\n";//Если пользователь ввёл число меньше 1 и больше 9 то выводится на экран сообщение "Vvedite chislo ot 1 do 9:"
        std::cin >> move;//Запрашиваем с помощью std::cin >> у пользователя другой вход move(ввод числа от 1 до 9)

    }
    return move;//Возвращаем оператором return  значение  “move”
}
//=============================функция play_and_get_winner============================================================================================================================================================================================

char play_and_get_winner() //функция play_and_get_winner() она будит возвращать char(символ) т.е. сыграть в игру и получить выигравшего
{
    int turn = 1;//переменная turn(ход) типа int изначально будит первой ход и ровняться= 1

    while(!has_wonQ('X') && !has_wonQ('0')) //while(не! выиграл пользовательhas_wonQ играющий иксом(X)('x') и&&  не! выиграл пользовательhas_wonQ играющий ноликом(О)('О')) то выполняется код ниже
    {
        clearscreen();// очищает окно консоли
        int move = get_move();//Вызывается функция get_move()и помещается то что она вернет в переменную

        clearscreen();  // очищает окно консоли
        if(turn%2 == 1) //Строкой if(i%2 == 0) проверяется чётное или нечётное число ввёл пользователь т.е. если i по модулю 2 равняется 1, то это чётный ход,
        {
            board[move-1]='X';//то тогда задаётся значение   ='X'
            if(has_wonQ('X')) //ifесли(has_wonQ('X')пользователь играющий за 'X' если он выиграл
            {
                std::cout <<"X,Pozdravlyau vi vuigrali!\n";//то печатается поздравление "X,Pozdravlyau vi vuigrali!"
                return 'X'; // возвращаетreturn из функции'X' что пользователь играющий 'X' выиграл
            }

        }
        else                     // Все остальные ходы будут нечётные,
        {
            board[move-1]='0';//то тогда задаётся значение   ='О'
            if(has_wonQ('0')) //ifесли(has_wonQ('X')пользователь играющий за 'X' если он выиграл
            {
                std::cout <<"O,Pozdravlyau vi vuigrali!\n";//то печатается поздравление "O,Pozdravlyau vi vuigrali!"
                return '0';       // возвращаетreturn из функции'X' что пользователь играющий 'X' выиграл
            }
        }
        turn++;                 //В конце цикла говорится turn(ход) увеличить на единицу++
        if(turn == 10)          //ifесли(turnвход ==ровняется 10). Ecли ввод равен 10, то НЕЧЬЯ. T.е. ставить крестик или нолик некуда
        {
            std::cout << "nechya\n";//тогда выводится на экран сообщение "nechya"
            return 'D';             //и операторreturn возвращает значение D
        }
    }
}
//========================================Главная функция main=====================================================================================================================================================================================================================================================
int main()                         //Главная функция main
{
    std::cout <<"Privetstvuyu\n\n";//выводится приветственное сообщения "Privetstvuyu" средством std::cout и оператором <<
    std::string reply = "y";//декларируется стринг reply(ответ). reply(ответ) по началу "y"(то бишь ДА(YES))
    int x_wins=0, o_wins=0, ties=0;//перечень переменных типаint  x_wins=0(это количество раз когда пользователь играющий иксами выиграл), o_wins=0(это количество раз когда пользователь играющий ноликами выиграл), ties=0(количество нечьих)и всем присвоенно нулевое значение

    while(reply == "y") //Строится цикл while пока ответ положительный, т.е. пока ответ ==ровняется "y"
    {
        clearboard();//функция void clearboard()которая очищает доску.
        char winner = play_and_get_winner();//play_and_get_winner()(главный цикл), и дать   char winner(выигравший). char winner ровняется= play_and_get_winner()
        print_board("\t  ");//пишется строка print_board() т.е. используется функция чтобы ещё раз напечатать доску(board), а в функции main талб\t     print_board("\t  ")

        switch(winner) //Пишется switch(это конструкция “если, то” при разных значениях ((winner)выигравший) будут выполнятся разные куски кода)
        {
        case 'X':    //Первое значениеcase 'X', если выграл пользователь играющий иксами
            x_wins++;  //тогда переменная x_wins увеличивается на единицу++
            break;     //и останавливается break
        case '0':     //Второеое значениеcase 'О', если выграл пользователь играющий ноликами
            o_wins++;  //тогда переменнаяо_wins увеличивается на единицу++
            break;     //и останавливается break
        case 'D':     //Третье значениеcase 'D', если нечья
            ties++;    //тогда переменнаяties увеличивается на единицу++
            break;     //и останавливается break
        }

        std::cout << "\n\t*Winer statistic*\nPlayer X: " << x_wins//Прописывается статистика,выводится статистика на экран/в окно консоли с помощью std::cout << "Winer statistic\nPlayer X: " << x_wins, это сколько раз пользователь играющий Х выиграл
                  << ", Player 0: "<<o_wins << " and Ties: "<<ties<<"\n\n";//"Player 0: "<<o_wins << " and Ties: "<<ties<<" это сколько раз пользователь играющий О выиграл. Сколько нечьих,
        std::cout << "\n would you like to play again? (y/n): ";//"would you like to play again? (y/n):" задаётся вопрос: “желаете продолжить игру?”,
        std::cin  >> reply;//а с помощью объекта cin пользователь может ввести значениеreply(ответ) y, а если пользователь не хочет играть то нужно ввести n
        while(reply != "y" && reply !="n") //цикл while(пока значениеreply(ответ)  !=не равно "y" или&& пока значениеreply(ответ) !=не равно "n") то цикл бесконечен
        {
            std::cout << "please inter a valid reply (y/n):";//строка просит пользователя ввести ещё значение,если до этого небыло введино y или n
            std::cin  >> reply;//с помощью объекта cin выводит на экран введённое пользователем значение и опять проверяется в цикле.
        }

    }//


    return 0;//Оператор return возвращает функции main()  0(ноль)
}
