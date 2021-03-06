// An example book
#include <ansi.h> // add by -alickyuen@ds-
#define DELAY 60
inherit ITEM;
void create()
{
set_name("火把",({"torch"}));
set_weight(100);
set("value",10);
set("time",15);
set("unit","隻");
set("long","一支火把.. 你可以使用它 (use torch)。\n");
setup();
}

int do_use(object me,string arg)
{
 if(query("time")<1) 
 {
      tell_object(me,"這個火把已經燒完了!\n");	
      return 1;
 }
 if(arg=="torch") //use不加參數則會傳入物品名稱供核對.
 {
  if(this_object()->query_light())
  {
   write("這個火把已經在燃燒了!\n");	
  }
   else
   {
         this_object()->set("name","火把"HIR"(燃燒中)"NOR); // edit by-alickyuen@ds-
   	 this_object()->set("long","一支燃燒中的火把.. 你可以熄滅它 (use torch off)。\n");
   	 this_object()->start_light(1);
   	 this_object()->set("no_put","你不能把正在燃燒的火把放進那裡面。\n");
   	 this_object()->set("value",2);
   	 message_vision("$N點燃了火把。\n",me);
   	 call_out("deca",DELAY,0);
   }
  return 1;
 }
 if(arg=="off") //use 加上參數則只傳入參數
 {
  if(!this_object()->query_light())
  {
   write("這個火把並沒有點燃!\n");	
  } else
  {
  	this_object()->set("name","火把");
	message_vision("$N熄滅了火把。\n",me);
  	remove_call_out("deca");
  	this_object()->set("long","一支用過的火把.. 你可以使用它 (use torch)。\n");
  	this_object()->start_light(0);
  	this_object()->delete("no_put");
  }
  return 1;
 }
 return 0;
}

void deca(int flag)
{
 object ob;
 remove_call_out("deca");

 if(!this_object() ) return;
 if(!environment(this_object())) return;
 
 if(flag)
 {
	 remove_call_out("deca");
  return;
 }
 else
 {
	this_object()->set("time",this_object()->query("time")-1);
	this_object()->set("long","一支燃燒中的火把.. 你可以熄滅它 (use torch off)。\n"
	+"這支火把還可以使用"+this_object()->query("time")+"分鐘。\n");
	if(this_object()->query("time")>0)	call_out("deca",DELAY,0);
	else 
	{
	 if(living(environment(this_object())))
  		message_vision("$N身上的火把因為燒完而漸漸熄滅了。\n",environment(this_object()));
  		else tell_room(environment(this_object()),"火把因為燒完而熄滅了。\n");

	 ob=new("/open/always/badtorch");
	 ob->move(environment(this_object()));
	 destruct(this_object());
	}
   	return;
 }
   return;
}

void water_effect()
{
	object ob;
	if(query("time")<1) return;
	remove_call_out("deca");
	if(this_object()->query_light())
	{
		message_vision("火把的火被水給熄滅了。\n",this_object());
		this_object()->start_light(0);
	}
	ob=new("/open/always/badtorch");
	ob->set_name("濕掉的火把",({"torch","badtorch"}));
	ob->set("long","一隻濕掉的火把。\n");
	ob->move(environment(this_object()));
	destruct(this_object());
	return;
}
