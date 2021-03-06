// An example book
#define DELAY 60
inherit ITEM;
void create()
{
set_name("實業Ａ型磷光發生器",({"phosphorescence lighter","lighter"}));
set_weight(150);
set("value",50);
set("time",15);
set("unit","座");
set("long","一座由實業公司在A.U411年所研發的磷光發生器 (use lighter)。\n");
setup();
}

int do_use(object me,string arg)
{
 if(query("time")<1) 
 {
      tell_object(me,"這個磷光發生器的能源用完了。\n");	
      return 1;
 }
 if(arg=="lighter")
 {
  if(this_object()->query_light())
  {
   write("這個發光器正在使用中。\n");	
  }
   else
   {
   	 this_object()->set("name","實業Ａ型磷光發生器(使用中)");
   	 this_object()->set("long"," 一座由實業公司在A.U411年所研發的磷光發生器,並且沒有關上,你可以熄滅它 (use lighter off)。\n");
   	 this_object()->start_light(1);
   	 this_object()->set("value",5);
   	 message_vision("$N將發生器的開關打開。\n",me);
   	 call_out("deca",DELAY,0);
   }
  return 1;
 }
 if(arg=="off")
 {
  if(!this_object()->query_light())
  {
   write("這個磷光發生器並不在使用中。\n");	
  } else
  {
  	this_object()->set("name","實業Ａ型磷光發生器");
	message_vision("$N將發生器的開關關上。\n",me);
  	remove_call_out("deca");
  	this_object()->set("long","一座由實業公司在A.U411年所研發的磷光發生器 (use lighter)。\n");
  	this_object()->start_light(0);
  }
  return 1;
 }
 return 0;
}

void deca(int flag)
{
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
	this_object()->set("long"," 一座由實業公司在A.U411年所研發的磷光發生器,並且沒有關上,你可以熄滅它 (use lighter off)。\n"
    +"這個發生器還可以使用"+this_object()->query("time")+"分鐘。\n");
	if(this_object()->query("time")>0)	call_out("deca",DELAY,0);
	else 
	{
	 this_object()->start_light(0);
	 this_object()->set("long","已經用完的發光器。\n");
	 this_object()->set("name","無能源的發光器");
	 this_object()->set("value",0);
	 if(living(environment(this_object())))
  		message_vision("$N的磷光發生器因為用完能源而漸漸熄滅了。\n",environment(this_object()));
  		else tell_room(environment(this_object()),"磷光發生器因為用完能源而熄滅了。\n");
	}
   	return;
 }
   return;
}
