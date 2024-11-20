#include<stdio.h>
#include<string.h>

struct movie{
    char title[20];
    char genre[20];
    char director[20];
    int relYear;
    float rating;

};

void addMovie(struct movie movies[20], int *count);
void search(struct movie movies[20], int count);
void display(struct movie movies[20], int count);

int main(){
    int choice, count=0;
    struct movie movies[20]; //max movies = 20
    do{
    printf("\n----Movie Management System----\n");
    printf("\n1.Add Movies");
    printf("\n2.Search Movies by genre");
    printf("\n3.Display All Movies");
    printf("\n4.Exit");

    printf("\nEnter your choice: ");
    scanf("%d",&choice);
    getchar();
    switch (choice)
    {
    case 1:
        addMovie(movies, &count);
        break;
    case 2:
        search(movies, count);
        break;
    case 3:
        display(movies, count);
        break;
    case 4:
        printf("Exit");
        break;      
    default:
        printf("Invalid choice! Please try again.");
        break;
    }

    } while(choice!=4);

    return 0;
}
void addMovie(struct movie movies[20], int *count){
    if(*count >= 20){
        printf("Movie list is full! Cannot add more movies.\n");
    }
    struct movie nmovies;
    printf("Enter movie title: ");
    fgets(nmovies.title,sizeof(nmovies.title),stdin);
    nmovies.title[strcspn(nmovies.title, "\n")]='\0';
    printf("Enter movie genre: ");
    fgets(nmovies.genre,sizeof(nmovies.genre),stdin);
    nmovies.genre[strcspn(nmovies.genre, "\n")]='\0';
    printf("Enter movie dtrector: ");
    fgets(nmovies.director,sizeof(nmovies.director),stdin);
    nmovies.director[strcspn(nmovies.director, "\n")]='\0';
    printf("Enter movie release year: ");
    scanf("%d",&nmovies.relYear);
    getchar();
    printf("Enter movie rating: ");
    scanf("%f",&nmovies.rating);
    getchar();
    movies[*count] = nmovies;
    (*count)++;
    printf("Movie added successfully\n");

}
void search(struct movie movies[20], int count){
    char genre[20];
    int found = 0;
    printf("Enter a genre to search: ");
    fgets(genre, sizeof(genre), stdin);
    genre[strcspn(genre, "\n")] = '\0';

    printf("\nMovies in genre %s",genre);
    for(int i=0; i<count; i++){
        if(strcmp(movies[i].genre, genre) == 0){
            printf("\n");
            printf("\nTitle: %s\nDirector: %s\nRelease Year: %d\nRating: %.2f\n",movies[i].title, movies[i].director, movies[i].relYear
            , movies[i].rating);
            found = 1;
        }
    }
    if(!found){
        printf("No movies found in this genre!");
    }
}
void display(struct movie movies[20], int count){
    if(count == 0){
        printf("No movies to display!");
        return;
    }
    printf("\nAll Movies\n");
    for(int i=0; i<count; i++){
        printf("Title: %s\nGenre: %s\nDirector: %s\nRelease Year: %d\nRating: %.2f\n",movies[i].title,movies[i].genre, movies[i].director, movies[i].relYear
            , movies[i].rating);
    }
}
