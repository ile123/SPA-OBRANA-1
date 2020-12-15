#include "dictionary.h"

int readWord(FILE* fd, char* buffer)
{
	int c;

	do {
		c = fgetc(fd);
		if (c == EOF)
			return 0;
	} while (!isalpha(c));

	do {
		*buffer = tolower(c);
		buffer++;
		c = fgetc(fd);
		if (c == 146)
			c = '\'';
	} while (isalpha(c) || c == '\'');

	*buffer = '\0';
	return 1;
}

void main()
{
	FILE* fd;
	char buffer[1024];
	Dictionary dict,novi_dict,kopirani_list,nova_lista;
	fd = fopen("liar.txt", "rt");
	if (fd == NULL)
	{
		printf("Error opening file.\n");
		return;
	}
	dict = create();
	while (readWord(fd, buffer))
	{
		add(dict, buffer);
	}
	fclose(fd);
	//dodaj_prije_odredenog_elemeata(dict, "a", "KOKO");
	//dodavanje_prije_odredenog_indeks(dict, 3, "Bubamara");
	//dict = obrnuta_lista(dict);
	//brisanje_pod_odredenim_uvjetima(dict);
	//print(novi_dict);
	//brisanje_odredenog_elemenata( dict,"Sotona");
    dodavanje_elementa_nakon_nekog_uvjeta(dict);
	//kopirani_list = create();
    //kopirani_elemnti_nova_lista(kopirani_list,dict, 7);
	//zamjena_prvi_zdanji(dict);
	//nova_lista = create();
	//lista_sa_odrdedenim_rjecima(dict,nova_lista);
	print(dict);
	//filterDictionary(dict, filter);
	printf("\n\n\n");
	printf("Filtrinaraanranran rjecnik:\n");
	printf("\n\n\n");
	//print(nova_lista);
	//print(dict);
	//destroy(dict);

}