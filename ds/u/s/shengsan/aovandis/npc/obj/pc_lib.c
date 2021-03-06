// 圖書館電腦
#include <path.h>
inherit ITEM;

object bookroom;

void create()
{
	set_name("圖書館電腦",({"library computer","computer"}) );
	set("long",@LONG
	你可以透過這台電腦查詢並為您取出你要的書籍。

	seek [書名][-k 類別][-n 編號][-a 作者]
	getbook [編號]
LONG
	);
	set_weight(15000);
	if(clonep() )
		set_default_object(__FILE__);
	else
	{
		set("value",75000);
		set("unit","台");   //luky
	}
	set("no_get",1);
	set("no_sac",1);
	set("bookroom",SHENGSAN2"aovandis/bookroom");
	setup();
}

void init() 
{
//	::init();
	add_action("do_seek","seek");
	add_action("do_getbook","getbook");

}

int sort_item(object ob1, object ob2)
{
	return strcmp(base_name(ob1),base_name(ob2));
}

int seek_name(string name)
{
	object *books;
	int i,gotit;
	string line,tmp,tmp2;

	if(!bookroom) return 0;
	books = all_inventory(bookroom);
	books = sort_array(books, "sort_item", this_object());

	line = sprintf(	"搜尋書名為: %s\n"
			"=============================================================\n"
			"= 編 號 = 書                          名 = 作    者 = 數 量 =\n"
			"=============================================================\n",
			name);
	for(i=0;i<sizeof(books);i++)
	{
		if(sscanf(books[i]->query("name"),"%s"+name+"%s",tmp,tmp2)==2)
		{
			line += sprintf(
				"= %5d = %-30s = %-8s = %5d =\n",
				books[i]->query("bookno"),
				books[i]->query("name"),
				books[i]->query("bookauthor"),
				1);
			gotit++;
		}
	}
	if(gotit)
		line += sprintf("=============================================================\n");
	line += sprintf("共搜尋到 %d 筆符合條件的資料...\n",gotit);

	this_player()->start_more(line);

	return 1;
}

int seek_kind(string kind)
{
	object *books;
	int i,j,gotit;
	string line,*kindarry;

	if(!bookroom) return 0;
	books = all_inventory(bookroom);
	books = sort_array(books, "sort_item", this_object());

	line = sprintf(	"搜尋圖書種類為: %s\n"
			"=============================================================\n"
			"= 編 號 = 書                          名 = 作    者 = 數 量 =\n"
			"=============================================================\n",
			kind);
	for(i=0;i<sizeof(books);i++)
	{
		kindarry = books[i]->query("bookkind");
		for(j=0;j<sizeof(kindarry);j++)
		{
			if(kindarry[j] == kind)
			{
				line += sprintf(
					"= %5d = %-30s = %-8s = %5d =\n",
					books[i]->query("bookno"),
					books[i]->query("name"),
					books[i]->query("bookauthor"),
					1);
				gotit++;
			}
		}
	}
	if(gotit)
		line += sprintf("=============================================================\n");
	line += sprintf("共搜尋到 %d 筆符合條件的資料...\n",gotit);

	this_player()->start_more(line);

	return 1;
}

int seek_bookno(int bookno)
{
	object *books;
	int i,gotit;
	string name,line,author;

	if(!bookroom) return 0;
	books = all_inventory(bookroom);
	for(i=0;i<sizeof(books);i++)
	{
		if(books[i]->query("bookno") == bookno)
		{
			name = books[i]->query("name");	
			author = books[i]->query("bookauthor");
			gotit++;
		}
	}
	if(gotit)
	{
		line = sprintf(
			"搜尋圖書編號為: %d\n"
			"=============================================================\n"
			"= 編 號 = 書                          名 = 作    者 = 數 量 =\n"
			"=============================================================\n"
			"= %5d = %-30s = %-8s = %5d =\n"
			"=============================================================\n",
			bookno,bookno,name,author,gotit);
	}
	else line = "Sorry...未搜尋到您要找的圖書...可能已經被別人借走囉。\n";
	write(line);
	return 1;
}

int seek_author(string author)
{
	object *books;
	int i,gotit;
	string line;

	if(!bookroom) return 0;
	books = all_inventory(bookroom);
	books = sort_array(books, "sort_item", this_object());

	line = sprintf(	"搜尋圖書作者為: %s\n"
			"=============================================================\n"
			"= 編 號 = 書                          名 = 作    者 = 數 量 =\n"
			"=============================================================\n",
			author);
	for(i=0;i<sizeof(books);i++)
	{
		if(books[i]->query("bookauthor") == author)
		{
			line += sprintf(
				"= %5d = %-30s = %-8s = %5d =\n",
				books[i]->query("bookno"),
				books[i]->query("name"),
				books[i]->query("bookauthor"),
				1);
			gotit++;
		}
	}
	if(gotit)
		line += sprintf("=============================================================\n");
	line += sprintf("共搜尋到 %d 筆符合條件的資料...\n",gotit);

	this_player()->start_more(line);

	return 1;
}

int do_seek(string arg)
{
	int seekno,bookno;
	string kind,name,author;
	if(!arg) return notify_fail("seek [書名][-k 類別][-n 編號][-a 作者]\n");
	if(!bookroom=load_object(this_object()->query("bookroom"))) return 0;
	if(sscanf(arg,"-%s",kind))
	{
		if(sscanf(arg,"-k %s",kind)==1)
			seekno = 2;
		else if(sscanf(arg,"-n %d",bookno)==1)
			seekno = 3;
		else if(sscanf(arg,"-a %s",author)==1)
			seekno = 4;
		else return notify_fail("seek [書名][-k 類別][-n 編號][-a 作者]\n");
	}
	else
	{
		seekno = 1;
		name = arg;
	}

	switch(seekno)
	{
		case 1: seek_name(name);break;
		case 2: seek_kind(kind);break;
		case 3: seek_bookno(bookno);break;
		case 4: seek_author(author);break;
		default: return notify_fail("seek [書名][-k 類別][-n 編號][-a 作者]\n");
	}
	return 1;
}

int do_getbook(string arg)
{
	int gotit,bookno;
	object *books,me,ob;

	if(!arg) return notify_fail("getbook [編號]\n");
	if(sscanf(arg,"%d",bookno)!=1) return notify_fail("getbook [編號]\n");
	if(!bookroom=load_object(this_object()->query("bookroom"))) return 0;
	me = this_player();

	if(ob=present("book"+bookno,bookroom))
	{
		gotit++;
		if(!me) return 0;
	 	ob->move(me);
	 	bookroom->save();
		me->save();
		message_vision("\n$n控制圖書館的自動化設備，快速的將『"+ob->query("name")+"』拿給了$N。\n",me,this_object());
	}
	else
		write("Sorry...圖書館內目前並沒有編號為 "+bookno+" 的圖書。\n");

	return 1;
}