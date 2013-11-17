<?php 
if(!isset($_SESSION)) 
    { 
        session_start(); 
    } 
if(!isset($_SESSION["erab"]))
{
    include_once 'index.php';
    exit;
}
?>
