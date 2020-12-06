<!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8" />
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <title>Przykład 3</title>
    <meta name="viewport" content="width=device-width, initial-scale=1">
</head>
<body>
    <?php
        $jezyki = [
            'Język 1' => 'PHP', 'Język 2' => 'C', 'Język 3' => 'C++', 
            'Język 4' => 'Java', 'Język 5' => 'C#', 'Język 6' => 'Ruby', 
            'Język 7' => 'Python'
        ];
        
        foreach($jezyki as $klucz => $wartosc) {
            echo "<p>$klucz: <strong>$wartosc</strong>";
        }
    ?>

    <?php foreach($jezyki as $klucz => $wartosc): ?>
        <p><?=$klucz ?>: <strong><?=$wartosc ?></strong>
    <?php endforeach; ?>
</body>
</html>