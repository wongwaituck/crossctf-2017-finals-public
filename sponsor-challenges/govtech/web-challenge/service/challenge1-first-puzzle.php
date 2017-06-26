<?php

declare(strict_types=1);

$a = rand(0,100);

if ($a < 30 ) {

?>


<pre>
   ___                               _                      _      _                                           _
  |   \    ___     __      ___    __| |    ___      o O O  | |_   | |_      ___      o O O   __      ___    __| |    ___      o O O
  | |) |  / -_)   / _|    / _ \  / _` |   / -_)    o       |  _|  | ' \    / -_)    o       / _|    / _ \  / _` |   / -_)    o
  |___/   \___|   \__|_   \___/  \__,_|   \___|   TS__[O]  _\__|  |_||_|   \___|   TS__[O]  \__|_   \___/  \__,_|   \___|   TS__[O]
_|"""""|_|"""""|_|"""""|_|"""""|_|"""""|_|"""""| {======|_|"""""|_|"""""|_|"""""| {======|_|"""""|_|"""""|_|"""""|_|"""""| {======|
"`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-'./o--000'"`-0-0-'"`-0-0-'"`-0-0-'./o--000'"`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-'./o--000'
</pre>

<?php

}
else if ($a >= 30 && $a <60) {

?>

<pre>

 ______   ______   ______   ______   ______   ______       _________  ___   ___   ______       ______   ______   ______   ______
/_____/\ /_____/\ /_____/\ /_____/\ /_____/\ /_____/\     /________/\/__/\ /__/\ /_____/\     /_____/\ /_____/\ /_____/\ /_____/\
\:::_ \ \\::::_\/_\:::__\/ \:::_ \ \\:::_ \ \\::::_\/_    \__.::.__\/\::\ \\  \ \\::::_\/_    \:::__\/ \:::_ \ \\:::_ \ \\::::_\/_
 \:\ \ \ \\:\/___/\\:\ \  __\:\ \ \ \\:\ \ \ \\:\/___/\      \::\ \   \::\/_\ .\ \\:\/___/\    \:\ \  __\:\ \ \ \\:\ \ \ \\:\/___/\
  \:\ \ \ \\::___\/_\:\ \/_/\\:\ \ \ \\:\ \ \ \\::___\/_      \::\ \   \:: ___::\ \\::___\/_    \:\ \/_/\\:\ \ \ \\:\ \ \ \\::___\/_
   \:\/.:| |\:\____/\\:\_\ \ \\:\_\ \ \\:\/.:| |\:\____/\      \::\ \   \: \ \\::\ \\:\____/\    \:\_\ \ \\:\_\ \ \\:\/.:| |\:\____/\
    \____/_/ \_____\/ \_____\/ \_____\/ \____/_/ \_____\/       \__\/    \__\/ \::\/ \_____\/     \_____\/ \_____\/ \____/_/ \_____\/


</pre>


<?php

}
else {

?>
<pre>
  _____                     _        _   _                          _
 |  __ \                   | |      | | | |                        | |
 | |  | | ___  ___ ___   __| | ___  | |_| |__   ___    ___ ___   __| | ___
 | |  | |/ _ \/ __/ _ \ / _` |/ _ \ | __| '_ \ / _ \  / __/ _ \ / _` |/ _ \
 | |__| |  __/ (_| (_) | (_| |  __/ | |_| | | |  __/ | (_| (_) | (_| |  __/
 |_____/ \___|\___\___/ \__,_|\___|  \__|_| |_|\___|  \___\___/ \__,_|\___|



</pre>

<?php

}


?>


<?php

if (isset($_POST['answer'])) {
    $input = $_POST['answer'];

//    $substitutions = array(
//        '&' => '',
//        ';' => '',
//        '|' => '',
//        '-' => '',
//        '$' => '',
//        '(' => '',
//        ')' => '',
//        '`' => '',
//        '|' => '',
//        '"' => '',
//        "'" => '',
//    );
//
//    $input = str_replace( array_keys ($substitutions), '', $input);
//
//    echo $input;
//    echo "<br><br>";


//    $input = str_replace('"', '', $input);
//    $input = str_replace("'", '', $input);
//    $input = str_replace("&", '', $input);
//    $input = str_replace("|", '', $input);
//    $input = str_replace(";", '', $input);
//    $input = str_replace("(", '', $input);
//    $input = str_replace(")", '', $input);
//    $input = str_replace("`", '', $input);
//    $input = str_replace("$", '', $input);
//    $input = str_replace("#", '', $input);
//    $input = str_replace("@", '', $input);
//    $input = str_replace("\\", '', $input);


    //$a = '12';

   $a = shell_exec("./challenge1 challenge1 " . escapeshellarg($input));

    if (strcmp($a, "TRUE") == 0 ) {
        ?>

            Congratulations! You have got the first flag. Proceeding to Challenge 2. <br>

<!--            <form action="challenge1-second-puzzle.php?firstchallenge=base4" method="GET">-->
<!--                <input type="hidden" value="base4">-->
<!--                <input type="submit" value="Proceed to Challenge 2">-->
<!--            </form>-->
            <button onclick="location.href='challenge1-second-puzzle.php?firstchallenge=base4'">Proceed to Challenge 2</button>

        <?php
    }
    else {

        echo $a;
        ?>
        <form action="challenge1-first-puzzle.php" method="post">
            <table>
                <tbody>
                <tr>
                    <td>Input flag:</td>
                    <td><input type="text" name="answer" autocomplete="off"></td>
                    <td><input type="submit" value="Submit"></td>
                </tr>
                </tbody>
            </table>
        </form>
        <?php
    }
}
else {

    $a = shell_exec("./challenge1 challenge1");


    echo $a;
?>

        <form action="challenge1-first-puzzle.php" method="post">
            <table>
                <tbody>
                <tr>
                    <td>Input flag:</td>
                    <td><input type="text" name="answer" autocomplete="off"/></td>
                    <td><input type="submit" value="Submit"></td>
                </tr>
                </tbody>
            </table>
        </form>
<?php


}




?>

