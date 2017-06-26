<?php

    if (isset($_GET['firstchallenge']) || isset($_POST['answer']) ) {
        if (strcmp($_GET['firstchallenge'],"base4") == 0 || isset($_POST['answer'])) {
            if (isset($_POST['answer'])) {
                if (strcmp($_POST['answer'],"GovTech{ABC}") == 0) {
                    header('Location: congratulations.php?bigboss');
                }
            }
?>
<head>
    <title>Tic-Tac-Toe</title>
    <style>
        table {
            border-collapse: collapse
        }

        tr {
            height: 50px;
        }

        th, td {
            width: 50px;
            text-align: center;
        }

        tbody {
            display: block;
            height: 50px;
            overflow: visible;
        }

        .top-only {
            border-top: thick solid #000000;
        }

        .bottom-only {
            border-bottom: thick solid #000000;
        }

        .left-only {
            border-left: thick solid #000000;
        }

        .right-only {
            border-right: thick solid #000000;
        }

        .mapping {
            font-size: small
        }

        .left_side {
            width: 50%;
            float: left;
        }

        .right_side {
            width: 50%;
            float: right;
        }

        .question_left {
            width: 23%;
            float: left;
            margin: 1%;
        }

        .mapping_left{
            width: 23%;
            float: left;
            margin: 5%;
        }

        .marking {
            color: red
        }
    </style>
</head>


<h1>Tic-Tac-Toe</h1>
<h3>Instructions</h3>
<ol>
    <li>The flag is encoded in the Tic-Tac-Toe format.</li>
    <li>The task is to get the flag.</li>
</ol>

<div style="height:770px">
    <div class="left_side">
        <h3>Tic-Tac Toe to ASCII characters mapping:</h3>

        <div class="mapping_left">
            <table width="250" height="150">
                <tr>
                    <td class="right-only bottom-only">x</td>
                    <td class="bottom-only">x</td>
                    <td class="left-only bottom-only"></td>
                    <td></td>
                    <td></td>
                </tr>
                <tr>
                    <td class="right-only top-only">o</td>
                    <td>o</td>
                    <td class="left-only">o</td>
                    <td></td>
                    <td></td>
                </tr>
                <tr>
                    <td class="right-only top-only"></td>
                    <td class="top-only"></td>
                    <td class="left-only top-only"></td>
                    <td></td>
                    <td></td>
                </tr>
            </table>
        </div>
        <div class="mapping_left">
            <table width="250" height="150">
                <tr>
                    <td class="right-only bottom-only">o</td>
                    <td class="bottom-only">o</td>
                    <td class="left-only bottom-only">o</td>
                    <td></td>
                    <td></td>
                </tr>
                <tr>
                    <td class="right-only top-only"></td>
                    <td>x</td>
                    <td class="left-only"></td>
                    <td></td>
                    <td class="mapping"><h2> &rarr; a </h2></td>
                </tr>
                <tr>
                    <td class="right-only top-only"></td>
                    <td class="top-only">x</td>
                    <td class="left-only top-only"></td>
                    <td></td>
                    <td></td>
                </tr>
            </table>
        </div>
        <br><br>
        <div style="clear:both;" class="mapping_left">
            <table width="250" height="150">
                <tr>
                    <td class="right-only bottom-only"></td>
                    <td class="bottom-only"></td>
                    <td class="left-only bottom-only"></td>
                    <td></td>
                    <td></td>
                </tr>
                <tr>
                    <td class="right-only top-only">o</td>
                    <td>o</td>
                    <td class="left-only">o</td>
                    <td></td>
                    <td></td>
                </tr>
                <tr>
                    <td class="right-only top-only"></td>
                    <td class="top-only">x</td>
                    <td class="left-only top-only">x</td>
                    <td></td>
                    <td></td>
                </tr>
            </table>
        </div>
        <div class="mapping_left">
            <table width="250" height="150">
                <tr>
                    <td class="right-only bottom-only">o</td>
                    <td class="bottom-only">o</td>
                    <td class="left-only bottom-only">o</td>
                    <td></td>
                    <td></td>
                </tr>
                <tr>
                    <td class="right-only top-only"></td>
                    <td>x</td>
                    <td class="left-only"></td>
                    <td></td>
                    <td class="mapping"><h2> &rarr; a </h2></td>
                </tr>
                <tr>
                    <td class="right-only top-only"></td>
                    <td class="top-only">x</td>
                    <td class="left-only top-only"></td>
                    <td></td>
                    <td></td>
                </tr>
            </table>
        </div>
        <br><br>
        <div style="clear:both;" class="mapping_left">
            <table width="250" height="150">
                <tr>
                    <td class="right-only bottom-only"></td>
                    <td class="bottom-only"></td>
                    <td class="left-only bottom-only"></td>
                    <td></td>
                    <td></td>
                </tr>
                <tr>
                    <td class="right-only top-only">o</td>
                    <td>o</td>
                    <td class="left-only">o</td>
                    <td></td>
                    <td class="mapping"></td>
                </tr>
                <tr>
                    <td class="right-only top-only"></td>
                    <td class="top-only">x</td>
                    <td class="left-only top-only">x</td>
                    <td></td>
                    <td></td>
                </tr>
            </table>
        </div>
        <div class="mapping_left">
            <table width="250" height="150">
                <tr>
                    <td class="right-only bottom-only">x</td>
                    <td class="bottom-only">x</td>
                    <td class="left-only bottom-only">x</td>
                    <td></td>
                    <td></td>
                </tr>
                <tr>
                    <td class="right-only top-only"></td>
                    <td>o</td>
                    <td class="left-only"></td>
                    <td></td>
                    <td class="mapping"><h2> &rarr; i </h2></td>
                </tr>
                <tr>
                    <td class="right-only top-only"></td>
                    <td class="top-only">o</td>
                    <td class="left-only top-only"></td>
                    <td></td>
                    <td></td>
                </tr>
            </table>
        </div>
        <br><br>
        <div style="clear:both;" class="mapping_left">
            <table width="250" height="150">
                <tr>
                    <td class="right-only bottom-only"></td>
                    <td class="bottom-only">x</td>
                    <td class="left-only bottom-only">x</td>
                    <td></td>
                    <td></td>
                </tr>
                <tr>
                    <td class="right-only top-only">o</td>
                    <td>o</td>
                    <td class="left-only">o</td>
                    <td></td>
                    <td></td>
                </tr>
                <tr>
                    <td class="right-only top-only"></td>
                    <td class="top-only"></td>
                    <td class="left-only top-only"></td>
                    <td></td>
                    <td></td>
                </tr>
            </table>
        </div>
        <div class="mapping_left">
            <table width="250" height="150">
                <tr>
                    <td class="right-only bottom-only">x</td>
                    <td class="bottom-only">x</td>
                    <td class="left-only bottom-only">x</td>
                    <td></td>
                    <td></td>
                </tr>
                <tr>
                    <td class="right-only top-only"></td>
                    <td>o</td>
                    <td class="left-only"></td>
                    <td></td>
                    <td class="mapping"><h2> &rarr; i </h2></td>
                </tr>
                <tr>
                    <td class="right-only top-only">o</td>
                    <td class="top-only"></td>
                    <td class="left-only top-only">o</td>
                    <td></td>
                    <td></td>
                </tr>
            </table>
        </div>
    </div>

    <div class="right_side">
        <h3>Clues</h3>
        <ol>
            <li> The key is to win the game.</li>
            <br><br>
            <li>
                <span>&nbsp;</span>
                <div>
                    <table width="250" height="150">
                        <tr>
                            <td class="right-only bottom-only">0</td>
                            <td class="bottom-only">7</td>
                            <td class="left-only bottom-only">6</td>
                        </tr>
                        <tr>
                            <td class="right-only top-only">1</td>
                            <td>4</td>
                            <td class="left-only">3</td>
                        </tr>
                        <tr>
                            <td class="right-only top-only">2</td>
                            <td class="top-only">5</td>
                            <td class="left-only top-only">0</td>
                        </tr>
                    </table>
                </div>
            </li>
            <br><br>
            <li> Require the following truth table.</li>
            <br> <img src="/challenge/logic.png">
            <br><br>
            <li> Circle = 0, Cross = 1</li>
            <br><br>
            <li><a href="http://www.asciitable.com/" target="_blank">www.asciitable.com</a></li>
        </ol>
    </div>

</div>

<br><br>


<div style="clear: both; height: 100%;">


<h3>Find the hidden flag: (Read from left to right then row by row)</h3>

    <div class="question_left">
        <table width="150" height="150">
            <tr>
                <td class="right-only bottom-only">o</td>
                <td class="bottom-only"></td>
                <td class="left-only bottom-only">x</td>
            </tr>
            <tr>
                <td class="right-only top-only"></td>
                <td>o</td>
                <td class="left-only">x</td>
            </tr>
            <tr>
                <td class="right-only top-only"></td>
                <td class="top-only"></td>
                <td class="left-only top-only">o</td>
            </tr>
        </table>
    </div>
    <div class="question_left">
        <table width="150" height="150">
            <tr>
                <td class="right-only bottom-only">x</td>
                <td class="bottom-only"></td>
                <td class="left-only bottom-only">x</td>
            </tr>
            <tr>
                <td class="right-only top-only"></td>
                <td></td>
                <td class="left-only"></td>
            </tr>
            <tr>
                <td class="right-only top-only">o</td>
                <td class="top-only">o</td>
                <td class="left-only top-only">o</td>
            </tr>
        </table>
    </div>
    <div class="question_left">
        <table width="150" height="150">
            <tr>
                <td class="right-only bottom-only"></td>
                <td class="bottom-only"></td>
                <td class="left-only bottom-only">x</td>
            </tr>
            <tr>
                <td class="right-only top-only">o</td>
                <td>o</td>
                <td class="left-only">o</td>
            </tr>
            <tr>
                <td class="right-only top-only"></td>
                <td class="top-only"></td>
                <td class="left-only top-only">x</td>
            </tr>
        </table>
    </div>
    <div class="question_left">
        <table width="150" height="150">
            <tr>
                <td class="right-only bottom-only"></td>
                <td class="bottom-only"></td>
                <td class="left-only bottom-only"></td>
            </tr>
            <tr>
                <td class="right-only top-only">o</td>
                <td>o</td>
                <td class="left-only"></td>
            </tr>
            <tr>
                <td class="right-only top-only">x</td>
                <td class="top-only">x</td>
                <td class="left-only top-only">x</td>
            </tr>
        </table>
    </div>
    <div class="question_left">
        <table width="150" height="150">
            <tr>
                <td class="right-only bottom-only"></td>
                <td class="bottom-only">x</td>
                <td class="left-only bottom-only">x</td>
            </tr>
            <tr>
                <td class="right-only top-only"></td>
                <td></td>
                <td class="left-only"></td>
            </tr>
            <tr>
                <td class="right-only top-only">o</td>
                <td class="top-only">o</td>
                <td class="left-only top-only">o</td>
            </tr>
        </table>
    </div>
    <div class="question_left">
        <table width="150" height="150">
            <tr>
                <td class="right-only bottom-only"></td>
                <td class="bottom-only"></td>
                <td class="left-only bottom-only"></td>
            </tr>
            <tr>
                <td class="right-only top-only">o</td>
                <td>o</td>
                <td class="left-only">o</td>
            </tr>
            <tr>
                <td class="right-only top-only">x</td>
                <td class="top-only"></td>
                <td class="left-only top-only">x</td>
            </tr>
        </table>
    </div>
    <div class="question_left">
        <table width="150" height="150">
            <tr>
                <td class="right-only bottom-only">x</td>
                <td class="bottom-only"></td>
                <td class="left-only bottom-only">o</td>
            </tr>
            <tr>
                <td class="right-only top-only">x</td>
                <td></td>
                <td class="left-only">o</td>
            </tr>
            <tr>
                <td class="right-only top-only"></td>
                <td class="top-only"></td>
                <td class="left-only top-only">o</td>
            </tr>
        </table>
    </div>
    <div class="question_left">
        <table width="150" height="150">
            <tr>
                <td class="right-only bottom-only">o</td>
                <td class="bottom-only"></td>
                <td class="left-only bottom-only"></td>
            </tr>
            <tr>
                <td class="right-only top-only"></td>
                <td>o</td>
                <td class="left-only">x</td>
            </tr>
            <tr>
                <td class="right-only top-only"></td>
                <td class="top-only">x</td>
                <td class="left-only top-only">o</td>
            </tr>
        </table>
    </div>
    <br><br>
    <div class="question_left">
        <table width="150" height="150">
            <tr>
                <td class="right-only bottom-only">x</td>
                <td class="bottom-only"></td>
                <td class="left-only bottom-only"></td>
            </tr>
            <tr>
                <td class="right-only top-only">o</td>
                <td>o</td>
                <td class="left-only">o</td>
            </tr>
            <tr>
                <td class="right-only top-only">x</td>
                <td class="top-only"></td>
                <td class="left-only top-only"></td>
            </tr>
        </table>
    </div>
    <div class="question_left">
        <table width="150" height="150">
            <tr>
                <td class="right-only bottom-only">x</td>
                <td class="bottom-only"></td>
                <td class="left-only bottom-only">o</td>
            </tr>
            <tr>
                <td class="right-only top-only"></td>
                <td></td>
                <td class="left-only">o</td>
            </tr>
            <tr>
                <td class="right-only top-only"></td>
                <td class="top-only">x</td>
                <td class="left-only top-only">o</td>
            </tr>
        </table>
    </div>
    <div class="question_left">
        <table width="150" height="150">
            <tr>
                <td class="right-only bottom-only">x</td>
                <td class="bottom-only"></td>
                <td class="left-only bottom-only"></td>
            </tr>
            <tr>
                <td class="right-only top-only">o</td>
                <td>o</td>
                <td class="left-only">o</td>
            </tr>
            <tr>
                <td class="right-only top-only"></td>
                <td class="top-only">x</td>
                <td class="left-only top-only"></td>
            </tr>
        </table>
    </div>
    <div class="question_left">
        <table width="150" height="150">
            <tr>
                <td class="right-only bottom-only">o</td>
                <td class="bottom-only"></td>
                <td class="left-only bottom-only"></td>
            </tr>
            <tr>
                <td class="right-only top-only">o</td>
                <td>x</td>
                <td class="left-only"></td>
            </tr>
            <tr>
                <td class="right-only top-only">o</td>
                <td class="top-only">x</td>
                <td class="left-only top-only"></td>
            </tr>
        </table>
    </div>
    <div class="question_left">
        <table width="150" height="150">
            <tr>
                <td class="right-only bottom-only"></td>
                <td class="bottom-only">x</td>
                <td class="left-only bottom-only"></td>
            </tr>
            <tr>
                <td class="right-only top-only">o</td>
                <td>o</td>
                <td class="left-only">o</td>
            </tr>
            <tr>
                <td class="right-only top-only"></td>
                <td class="top-only"></td>
                <td class="left-only top-only">x</td>
            </tr>
        </table>
    </div>
    <div class="question_left">
        <table width="150" height="150">
            <tr>
                <td class="right-only bottom-only"></td>
                <td class="bottom-only">o</td>
                <td class="left-only bottom-only">x</td>
            </tr>
            <tr>
                <td class="right-only top-only">o</td>
                <td>x</td>
                <td class="left-only"></td>
            </tr>
            <tr>
                <td class="right-only top-only">x</td>
                <td class="top-only"></td>
                <td class="left-only top-only"></td>
            </tr>
        </table>
    </div>
    <div class="question_left">
        <table width="150" height="150">
            <tr>
                <td class="right-only bottom-only">x</td>
                <td class="bottom-only"></td>
                <td class="left-only bottom-only">x</td>
            </tr>
            <tr>
                <td class="right-only top-only"></td>
                <td></td>
                <td class="left-only"></td>
            </tr>
            <tr>
                <td class="right-only top-only">o</td>
                <td class="top-only">o</td>
                <td class="left-only top-only">o</td>
            </tr>
        </table>
    </div>
    <div class="question_left">
        <table width="150" height="150">
            <tr>
                <td class="right-only bottom-only">x</td>
                <td class="bottom-only"></td>
                <td class="left-only bottom-only"></td>
            </tr>
            <tr>
                <td class="right-only top-only">x</td>
                <td></td>
                <td class="left-only">o</td>
            </tr>
            <tr>
                <td class="right-only top-only">x</td>
                <td class="top-only"></td>
                <td class="left-only top-only">o</td>
            </tr>
        </table>
    </div>
    <br><br>
    <div class="question_left">
        <table width="150" height="150">
            <tr>
                <td class="right-only bottom-only">o</td>
                <td class="bottom-only">x</td>
                <td class="left-only bottom-only">x</td>
            </tr>
            <tr>
                <td class="right-only top-only"></td>
                <td>o</td>
                <td class="left-only"></td>
            </tr>
            <tr>
                <td class="right-only top-only"></td>
                <td class="top-only"></td>
                <td class="left-only top-only">o</td>
            </tr>
        </table>
    </div>
    <div class="question_left">
        <table width="150" height="150">
            <tr>
                <td class="right-only bottom-only">o</td>
                <td class="bottom-only">o</td>
                <td class="left-only bottom-only">o</td>
            </tr>
            <tr>
                <td class="right-only top-only"></td>
                <td>x</td>
                <td class="left-only"></td>
            </tr>
            <tr>
                <td class="right-only top-only"></td>
                <td class="top-only">x</td>
                <td class="left-only top-only"></td>
            </tr>
        </table>
    </div>
    <div class="question_left">
        <table width="150" height="150">
            <tr>
                <td class="right-only bottom-only">o</td>
                <td class="bottom-only"></td>
                <td class="left-only bottom-only"></td>
            </tr>
            <tr>
                <td class="right-only top-only">x</td>
                <td>o</td>
                <td class="left-only">x</td>
            </tr>
            <tr>
                <td class="right-only top-only"></td>
                <td class="top-only"></td>
                <td class="left-only top-only">o</td>
            </tr>
        </table>
    </div>
    <div class="question_left">
        <table width="150" height="150">
            <tr>
                <td class="right-only bottom-only"></td>
                <td class="bottom-only">o</td>
                <td class="left-only bottom-only"></td>
            </tr>
            <tr>
                <td class="right-only top-only">x</td>
                <td>o</td>
                <td class="left-only"></td>
            </tr>
            <tr>
                <td class="right-only top-only">x</td>
                <td class="top-only">o</td>
                <td class="left-only top-only"></td>
            </tr>
        </table>
    </div>
    <div class="question_left">
        <table width="150" height="150">
            <tr>
                <td class="right-only bottom-only">o</td>
                <td class="bottom-only">x</td>
                <td class="left-only bottom-only"></td>
            </tr>
            <tr>
                <td class="right-only top-only"></td>
                <td>o</td>
                <td class="left-only"></td>
            </tr>
            <tr>
                <td class="right-only top-only">x</td>
                <td class="top-only"></td>
                <td class="left-only top-only">o</td>
            </tr>
        </table>
    </div>
    <div class="question_left">
        <table width="150" height="150">
            <tr>
                <td class="right-only bottom-only">o</td>
                <td class="bottom-only"></td>
                <td class="left-only bottom-only"></td>
            </tr>
            <tr>
                <td class="right-only top-only">o</td>
                <td></td>
                <td class="left-only">x</td>
            </tr>
            <tr>
                <td class="right-only top-only">o</td>
                <td class="top-only">x</td>
                <td class="left-only top-only"></td>
            </tr>
        </table>
    </div>
    <div class="question_left">
        <table width="150" height="150">
            <tr>
                <td class="right-only bottom-only"></td>
                <td class="bottom-only"></td>
                <td class="left-only bottom-only"></td>
            </tr>
            <tr>
                <td class="right-only top-only">x</td>
                <td>x</td>
                <td class="left-only"></td>
            </tr>
            <tr>
                <td class="right-only top-only">o</td>
                <td class="top-only">o</td>
                <td class="left-only top-only">o</td>
            </tr>
        </table>
    </div>
    <div class="question_left">
        <table width="150" height="150">
            <tr>
                <td class="right-only bottom-only"></td>
                <td class="bottom-only"></td>
                <td class="left-only bottom-only">x</td>
            </tr>
            <tr>
                <td class="right-only top-only"></td>
                <td>o</td>
                <td class="left-only">x</td>
            </tr>
            <tr>
                <td class="right-only top-only">o</td>
                <td class="top-only"></td>
                <td class="left-only top-only">x</td>
            </tr>
        </table>
    </div>
    <br><br>





    <br> <br><br> <br><br> <br><br> <br><br> <br><br> <br>
    <form action="challenge1-second-puzzle.php?firstchallenge#answer" method="post">
        <table id="answer">
            <tbody>
            <tr>
                <td>Initials:</td>
                <td><input type="text" name="answer" autocomplete="off"></td>
                <td><input type="submit" value="Submit"></td>
                <?php
                if (isset($_POST['answer'])) {
                    echo "<td class='marking'> Wrong answer </td>";
                }
                ?>
            </tr>
            </tbody>
        </table>
    </form>

</div>


            <?php
        }
        else {
        //    echo strcmp($_GET['firstchallenge'],"base4");
          //  echo $_GET['firstchallenge'];
            header('Location: challenge1-first-puzzle.php');
            die();
        }

    }
    else {
        //echo isset($_GET['firstchallenge']);
        header('Location: challenge1-first-puzzle.php');
        die();
    }


?>