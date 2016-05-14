<?php


echo "\n----------------------------------------------------------------------------------------------\n\n\n";
echo "test hexdump \n\n\n";
echo "\n----------------------------------------------------------------------------------------------\n\n\n";

// test compil
if ($handle = opendir('unit_test/instructions')) {
    while (false !== ($entry = readdir($handle))) {
		{
			if (strcmp($entry, ".") != 0 && strcmp($entry, "..") != 0)
			{
				if (($handle2 = opendir('unit_test/instructions/'.$entry)) != NULL)
				{
					echo "\n--------------------------------------------------------------\n";
					echo "\n$entry :\n";
					echo "\n--------------------------------------------------------------\n";
    				while (false !== ($entry2 = readdir($handle2))) {
						if (strcmp($entry2, ".") != 0 && strcmp($entry2, "..") != 0 && !strstr("$entry2", "test_err"))
						{
							echo "\n--------------------------------------------------------------\n";
							echo "test HEXDUMP : $entry2";
							echo "\n--------------------------------------------------------------\n";
							$search  = array('.s');
							$replace = array('.cor');
							$entry3 = str_replace($search, $replace, $entry2);
							exec("./ressources/asm unit_test/instructions/".$entry."/".$entry2);
							exec("hexdump unit_test/instructions/".$entry."/".$entry3." > t1");
							exec("./asm unit_test/instructions/".$entry."/".$entry2);
							exec("hexdump unit_test/instructions/".$entry."/".$entry3." > t2");
							exec('diff t1 t2 > t3');
							$contenuFichier=readfile("t3");
							echo "\n--------------------------------------------------------------\n";
							echo $contenuFichier;
							echo "\n--------------------------------------------------------------\n";
							echo "if nothing write before hexdump ok\n";
							echo "\n--------------------------------------------------------------\n";
						}
					}
				}
    			closedir($handle2);
			}
		}
    }
    closedir($handle);
}

echo "\n----------------------------------------------------------------------------------------------\n\n\n";
echo "test error \n\n\n";
echo "\n----------------------------------------------------------------------------------------------\n\n\n";

// test compil
if ($handle = opendir('unit_test/instructions')) {
    while (false !== ($entry = readdir($handle))) {
		{
			if (strcmp($entry, ".") != 0 && strcmp($entry, "..") != 0)
			{
				if (($handle2 = opendir('unit_test/instructions/'.$entry)) != NULL)
				{
					echo "$entry :\n\n\n";
    				while (false !== ($entry2 = readdir($handle2))) {
						if (strcmp($entry2, ".") != 0 && strcmp($entry2, "..") != 0 && !strstr($entry2, ".cor"))
						{
							echo "test : $entry2\n";
							exec("./asm unit_test/instructions/".$entry.'/'.$entry2);
						}
					}
				}
    			closedir($handle2);
			}
		}
    }
    closedir($handle);
}

// test dif

echo "\n----------------------------------------------------------------------------------------------\n\n\n";
echo "test DIFF flo\n\n\n";
echo "\n----------------------------------------------------------------------------------------------\n\n\n";

if ($handle = opendir('unit_test/instructions')) {
    while (false !== ($entry = readdir($handle))) {
		{
			if (strcmp($entry, ".") != 0 && strcmp($entry, "..") != 0)
			{
				if (($handle2 = opendir('unit_test/instructions/'.$entry)) != NULL)
				{
					echo "test DIFF on : $entry :\n";
    				while (false !== ($entry2 = readdir($handle2))) {
						if (strcmp($entry2, ".") != 0 && strcmp($entry2, "..") != 0 && strstr($entry2, ".cor"))
						{
							// echo("./corewar unit_test/instructions/".$entry."/".$entry2." -v 31  > test1\n");
							// echo("./ressources/corewar unit_test/instructions/".$entry."/".$entry2."  -v 31 > test2\n");
							exec("./corewar unit_test/instructions/".$entry."/".$entry2." -v 31 -d 100 > test1");
							exec("./ressources/corewar unit_test/instructions/".$entry."/".$entry2."  -v 31 -d 100 > test2");
							exec ("diff test1 test2");
						}
					}
				}
    			closedir($handle2);
			}
		}
    }
    closedir($handle);
}


echo "\n----------------------------------------------------------------------------------------------\n\n\n";
echo "RM .cor \n\n\n";
echo "\n----------------------------------------------------------------------------------------------\n\n\n";

exec("rm unit_test/instructions/**/**.cor");

echo "\n----------------------------------------------------------------------------------------------\n\n\n";
echo "test DIFF alexis\n\n\n";
echo "\n----------------------------------------------------------------------------------------------\n\n\n";
// test alexis

echo "-------- diff on ./corewar balzac -v 31 --------\n";
exec("./corewar ressources/champions/examples/balzac.cor -v 31  > test1");
exec("./ressources/corewar ressources/champions/examples/balzac.cor  -v 31 > test2");
exec ("diff test1 test2");
echo "-------- if nothing here diff OK --------\n";
// echo "-------- diff on ./corewar bee_gees -v 31 --------\n";
// exec("./corewar ressources/champions/examples/bee_gees.cor -v 31 > test1");
// exec("./ressources/corewar ressources/champions/examples/bee_gees.cor  -v 31 > test2");
// exec("diff test1 test2");
// echo "-------- if nothing here diff OK --------\n";
echo "-------- diff on ./corewar bigzork -v 31 --------\n";
exec("./corewar ressources/champions/examples/bigzork.cor -v 31  > test1");
exec("./ressources/corewar ressources/champions/examples/bigzork.cor -v 31 > test2");
exec("diff test1 test2");
echo "-------- if nothing here diff OK --------\n";
echo "-------- diff on ./corewar fluttershy -v 31 --------\n";
exec("./corewar ressources/champions/examples/fluttershy.cor  -v 31 > test1");
exec("./ressources/corewar ressources/champions/examples/fluttershy.cor -v 31 > test2");
exec("diff test1 test2");
echo "-------- if nothing here diff OK --------\n";
echo "-------- diff on ./corewar helltrain -v 31 --------\n";
exec("./corewar ressources/champions/examples/helltrain.cor -v 31  > test1");
exec("./ressources/corewar ressources/champions/examples/helltrain.cor  -v 31 > test2");
exec("diff test1 test2");
echo "-------- if nothing here diff OK --------\n";
echo "-------- diff on ./corewar turtle -v 31 --------\n";
exec("./corewar ressources/champions/examples/turtle.cor -v 31 > test1");
exec("./ressources/corewar ressources/champions/examples/turtle.cor -v 31 > test2");
exec("diff test1 test2");
echo "-------- if nothing here diff OK --------\n";
echo "-------- diff on ./corewar zork -v 31 --------\n";
exec("./corewar ressources/champions/examples/zork.cor -v 31 > test1");
exec("./ressources/corewar ressources/champions/examples/zork.cor -v 31 > test2");
exec("diff test1 test2");
echo "-------- if nothin here diff OK --------\n";
exec("rm test1 test2 t1 t2 t3");
?>
