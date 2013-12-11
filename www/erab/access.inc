<?php 
if(!isset($_SESSION)) 
    { 
        session_start(); 
    } 
if(!isset($_SESSION["erab"]))
{
    include '../index.php';
    exit;
}
?>
