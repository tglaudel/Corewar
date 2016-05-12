<?php

if ($handle = opendir('unit_test/instructions')) {
    while (false !== ($entry = readdir($handle))) {
		{
			if (strcmp($entry, ".") != 0 && strcmp($entry, "..") != 0)
			{
				if (($handle2 = opendir('unit_test/instructions/'.$entry)) != NULL)
				{
					echo "$entry :\n";
    				while (false !== ($entry2 = readdir($handle2))) {
						if (strcmp($entry2, ".") != 0 && strcmp($entry2, "..") != 0
							&& strstr($entry2, "test_err"))
						{
							exec("./asm /unit_test/instructions/".$entry.'/'.$entry2);
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
echo "test DIFF\n\n\n";
echo "\n----------------------------------------------------------------------------------------------\n\n\n";

exec("./corewar ressources/champions/examples/balzac.cor -v 31 > test1");
exec("./ressources/corewar ressources/champions/examples/balzac.cor -v 31 > test2");
exec ("diff test1 test2");
exec("./corewar ressources/champions/examples/bee_gees.cor -v 31 > test1");
exec("./ressources/corewar ressources/champions/examples/bee_gees.cor -v 31 > test2");
exec("diff test1 test2");
exec("./corewar ressources/champions/examples/bigzork.cor -v 31 > test1");
exec("./ressources/corewar ressources/champions/examples/bigzork.cor -v 31 > test2");
exec("diff test1 test2");
exec("./corewar ressources/champions/examples/fluttershy.cor -v 31 > test1");
exec("./ressources/corewar ressources/champions/examples/fluttershy.cor -v 31 > test2");
exec("diff test1 test2");
exec("./corewar ressources/champions/examples/helltrain.cor -v 31 > test1");
exec("./ressources/corewar ressources/champions/examples/helltrain.cor -v 31 > test2");
exec("diff test1 test2");
exec("./corewar ressources/champions/examples/turtle.cor -v 31 > test1");
exec("./ressources/corewar ressources/champions/examples/turtle.cor -v 31 > test2");
exec("diff test1 test2");
exec("./corewar ressources/champions/examples/zork.cor -v 31 > test1");
exec("./ressources/corewar ressources/champions/examples/zork.cor -v 31 > test2");
exec("diff test1 test2");
exec("rm test1");
exec("rm test2");
echo "\nif nothing write before DIFF OK\n";
?>
