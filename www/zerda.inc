<?php if(count(get_included_files()) ==1) header("Location: ./index.php"); 
	$fitx = "./Azalpena.txt";
	echo readfile($fitx);
?>
<br/>
