<html>
   <head>
      <meta http-equiv="Content-Type" content="text/html;charset=utf-8">
       <title>PHP Zajencie 1</title>
   </head>
   <body>
    <p>Zadanie 1</p>
        <table border="1px">  
        <?php
        for($i = 0; $i < 10; $i++) {
            if($i % 2 == 0)
                echo "<tr><td style='background-color:yellow'> Paragraf </td> <td  style='background-color:yellow'>#$i </td></tr>";
            else
                echo "<tr><td> Paragraf </td> <td>#$i </td></tr>";
        }
        ?>
        </table>  
       
    <p>Zadanie 2</p>
    <ul>
      <?php
         $jezyki = ['black', 'silver', 'gray', 'maroon', 'red', 'purple', 'fuchsia', 'green', 'lime','olive', 'yellow', 'navy', 'blue', 'teal' ,'aqua'];
         foreach($jezyki as $klucz) 
         { 
             echo "<li style='color: $klucz'><strong>$klucz</strong></li>"; 
         } 
       ?>
    </ul>
       


   </body>
</html>