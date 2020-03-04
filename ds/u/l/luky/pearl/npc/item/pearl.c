// An example book
inherit ITEM;
void create()
{
set_name("[1;36m©]©ú¯][0m",({"pearl"}));
set_weight(3000);
set("value",6000);
set("unit","Áû");
set("long",@NOTE
¤@Áû«Ü¬üÄRªº¬Ã¯], µo¥X²H²HªºÂÅ¦â¥ú¨~.
NOTE
);
set_temp("has_light",1);
setup();
}

void init()
{
 if(userp(environment(this_object()))) call_out("delete_pearl",6000+random(2000),this_player());
}

void delete_pearl(object me)
{
 if(!me) 
 {	
  if(environment(this_object()))
  {
   message_vision("$Nªº¯à¶q¯ÓºÉ.. ¤Æ¬°¤@°ï¯»¥½´²¥h¤F..\n",this_object());
   destruct(this_object());
   return;
  }
  else destruct(this_object());
  return;
 }
 
 if( me == environment(this_object()) )
 {
   tell_object(me,"©]©ú¯]ªº¯à¶q¯ÓºÉ.. ¤Æ¬°¤@°ï¯»¥½´²¥h¤F..\n");
//   me->delete_temp("has_light");
   destruct(this_object()); 
   return;
 }
   message_vision("$Nªº¯à¶q¯ÓºÉ.. ¤Æ¬°¤@°ï¯»¥½´²¥h¤F..\n",this_object());
   destruct(this_object());
   return;
}