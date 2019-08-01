#include "CItem.h"
#include "CFolder.h"
#include "Cfile.h"
void main()
{
	CFolder C("C");
	CFolder System("System");
	CFolder Windows("Windows");
	Cfile a_txt("a.txt", 123);
	Cfile b_doc("b.doc", 456);
	System.add(&a_txt);
	Windows.add(&b_doc);
	C.add(&System);
	C.add(&Windows);
	cout << "Noi dung o dia C ->" << endl;
	C.print(0); // print sub-files or folders? 1/0
	CItem* p = C.removeByName("System");
	cout << "Noi dung o dia C sau khi xoa thu muc System ->" << endl;
	C.print(0);

	p = C.findByname("b.doc");
	if (p != NULL)
	{
		cout << "Tim thay tap tin b.doc trong o dia C" << endl;
	}
	else
	{
		cout << "Khong tim thay tap tin b.doc trong o dia C" << endl;
	}
	p = C.findByname("a.txt");
	if (p != NULL)
	{
		cout << "Tim thay tap tin a.txt trong o dia C" << endl;
	}
	else
	{
		cout << "Khong tim thay tap tin a.txt trong o dia C" << endl;
	}
	p = C.findByname("Windows");
	if (p != NULL)
	{
		CFolder*k = dynamic_cast<CFolder*>(p);
		cout << "Tim thay thu muc Windows trong o dia C, noi dung thu muc Windows ->" << endl;
		k->setHidden(true, true); // set HIDDEN to folder p and all its items
		k->print(0);
		k->setHidden(false, true); // set UN-HIDDEN to folder p and all its items
	}
	else
	{
		cout << "Khong tim thay thu muc Windows trong o dia C" << endl;
	}

	system("pause");
}