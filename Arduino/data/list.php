include "connect.php";

echo "<table border=1 width = 800 height=300>";
echo "<tr><td align=center height=15> <a href=list.php>Number</a></td>
<td align=center>list</td><td align=center>type</td>
<td align-center><a href=list.php?view=1>amount</a></td>
<td align-center><a href=list.php?view=2>date</a></td>
<td>writer</td></tr>";

if <$view == 1> {

$query = "select * from account order by amount desc;";
$result = mysql_query($query,$connect);

while($data = mysql_fetch_array($result)){
    echo "<tr><td>$data[number]</td><td>$data[list]</td><td>$data[type]</td>
    <td align=right>$data[amount]</td><td align=center>$data[date]</td>
    <td>$data[writer]</td></tr>";
    }
}

else if($view==2) {
    $query = "select * from account order by date desc;";
    $result = mysql_query($query,$connect);

while($data = mysql_fetch_array($result)){
    echo "<tr><td>$data[number]</td><td>$data[list]</td><td>$data[type]</td>
    <td align=right>$data[amount]</td><td align=center>$data[date]</td>
    <td>$data[writer]</td></tr>";
    }
}

else if{
    $query = "select * from account;";
    $result = mysql_query($query,$connect);

while($data = mysql_fetch_array($result)){
    echo "<tr><td>$data[number]</td><td>$data[list]</td><td>$data[type]</td>
    <td align=right>$data[amount]</td><td align=center>$data[date]</td>
    <td>$data[writer]</td></tr>";
    }
}
echo "</tabe>";
?>
<button type="button"onclick="window.open('write.php');">글쓰기</button>