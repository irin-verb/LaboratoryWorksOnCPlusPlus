program matrix;
const
  n=3; //размерность
type 
  arr = array[1..n,1..n] of real;
var 
  A,B: arr; //наша матрица
  i,j,k,m:integer; //параметры циклов
  l:integer; //счетчик количества перестановок столбцов, чтобы определить знак определителя
  D,flag,koef: real; //D - определитель, flag - определитель-флаг для случая, когда строка нулевая
 
//вывод матрицы 
procedure output(A:arr;n:integer);
var i,j:integer;
Begin
  for i:=1 to n do
  begin
    for j:=1 to n do
      write(A[i,j]:8:2);
    writeln;
  end;
end;

//это для проверки 
//нахождение определителя через рекурсивную формулу без деления (в vba не получилось перенести)
//(раскладывает по первой строке и считает определители миноров, пока не дойдет до 2ого порядка) 
function det(A: arr; n: integer):real;
var 
  k,i,j: integer;
  D: real;
Begin
  if n=2 
  then D:=A[1,1]*A[2,2]-A[1,2]*A[2,1]
  else begin
    D:=0;
    for k:=1 to n do
      begin
      for j:=1 to n-1 do
      for i:=1 to n-1 do
      begin
        if j<k 
        then B[i,j]:=A[i+1,j]
        else B[i,j]:=A[i+1,j+1];
      end;
      if (1+k) mod 2=0 
      then D:=D+A[1,k]*det(B,n-1) 
      else D:=D-A[1,k]*det(B,n-1);
      end;
  end;
  det:=D;
end;

    
Begin 
  //задаем матрицу
  for i:=1 to n do
    for j:=1 to n do
    begin
      write('A[',i,';',j,'] = ');
      readln(A[i,j]);
    end;
  output(A,n);
  //провер очка
  writeln(det(A,n));
  

  l:=0;
  flag:=1;
  for k:=1 to n do
    for i:=k+1 to n do
    begin
      if A[k,k]=0 
      then begin
        for m:=k+1 to n do
        begin
          for j:=1 to n do       // это мы крч меняем 
            swap(A[j,k],A[j,m]); // стобцы местами
          writeln;
          output(A,n);//вывод для отладки
          inc(l);
          if A[k,k]<>0 then break; //если находим ненулевой элемент, перестаем менять столбцы местами
          if (A[k,k]=0) and (m=n) 
          then begin
            A[k,k]:=1; //если вся строчка нулевая, то мы тупо чтобы не было деления на ноль
            // заменяем элемент на единичку, но дальнейший определитель уже ошибочный 
            //и все равно в конце заменится на flag
            flag:=0; //оп, вот тут крч если строчка целиком нулевая, то определитель-флаг станет ноль 
          end;
        end;  
      end;
      //ну тут все по классике по Гауссу
      koef:=-A[i,k]/A[k,k]; 
      for j:=1 to n do
        A[i,j]:=A[i,j]+A[k,j]*koef
    end;
    
  D:=1;
  for i:=1 to n do
    D:=D*A[i,i];
  if l mod 2 = 1 then D:=-D;
  if flag=0 then D:=0; //ну вот и собсно замена на flag
  writeln;
  output(A,n);
  writeln(D);
end.