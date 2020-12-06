<!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8" />
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <title>Przykład 2</title>
    <meta name="viewport" content="width=device-width, initial-scale=1">
</head>
<body>
    <?php
        for($i = 0; $i < 10; $i++) {
            echo "<p>Paragraf #$i</p>";
        }
    ?>
        
    <?php for($i = 0; $i < 10; $i++): ?>
        <p>Paragraf #<?=$i ?></p>
    <?php endfor; ?>
</body>
</html>