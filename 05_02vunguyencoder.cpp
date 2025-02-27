#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Lớp cơ sở Book
class Book {
protected:
    string publisher;
    int year;

public:
    Book(string publisher, int year) : publisher(publisher), year(year) {}

    void display() {
        cout << "Publisher: " << publisher << endl;
        cout << "Year: " << year << endl;
    }
};

// Lớp con StudyBook (kế thừa từ Book)
class StudyBook : public Book {
protected:
    string subject;

public:
    StudyBook(string publisher, int year, string subject)
        : Book(publisher, year), subject(subject) {}

    void display() {
        Book::display();
        cout << "Subject: " << subject << endl;
    }
};

// Lớp con Textbook (kế thừa từ StudyBook)
class Textbook : public StudyBook {
private:
    vector<string> schools;

public:
    Textbook(string publisher, int year, string subject, vector<string> schools)
        : StudyBook(publisher, year, subject), schools(schools) {}

    void display() {
        StudyBook::display();
        cout << "Schools using this book: ";
        for (const string& school : schools) {
            cout << school << ", ";
        }
        cout << endl;
    }
};

// Lớp con ExerciseBook (kế thừa từ StudyBook)
class ExerciseBook : public StudyBook {
private:
    string difficultyLevel;

public:
    ExerciseBook(string publisher, int year, string subject, string difficultyLevel)
        : StudyBook(publisher, year, subject), difficultyLevel(difficultyLevel) {}

    void display() {
        StudyBook::display();
        cout << "Difficulty Level: " << difficultyLevel << endl;
    }
};

// Lớp con Fiction (kế thừa từ Book)
class Fiction : public Book {
protected:
    string ageLimit;
    string author;
    string translator;

public:
    Fiction(string publisher, int year, string ageLimit, string author, string translator)
        : Book(publisher, year), ageLimit(ageLimit), author(author), translator(translator) {}

    void display() {
        Book::display();
        cout << "Age Limit: " << ageLimit << endl;
        cout << "Author: " << author << endl;
        cout << "Translator: " << translator << endl;
    }
};

// Lớp con Novel (kế thừa từ Fiction)
class Novel : public Fiction {
protected:
    int chapters;

public:
    Novel(string publisher, int year, string ageLimit, string author, string translator, int chapters)
        : Fiction(publisher, year, ageLimit, author, translator), chapters(chapters) {}

    void display() {
        Fiction::display();
        cout << "Chapters: " << chapters << endl;
    }
};

// Lớp con RomanceNovel (kế thừa từ Novel)
class RomanceNovel : public Novel {
public:
    RomanceNovel(string publisher, int year, string ageLimit, string author, string translator, int chapters)
        : Novel(publisher, year, ageLimit, author, translator, chapters) {}

    void display() {
        Novel::display();
        cout << "Type: Romance Novel" << endl;
    }
};

// Lớp con DetectiveNovel (kế thừa từ Novel)
class DetectiveNovel : public Novel {
public:
    DetectiveNovel(string publisher, int year, string ageLimit, string author, string translator, int chapters)
        : Novel(publisher, year, ageLimit, author, translator, chapters) {}

    void display() {
        Novel::display();
        cout << "Type: Detective Novel" << endl;
    }
};

// Lớp con Comic (kế thừa từ Fiction)
class Comic : public Fiction {
private:
    vector<string> adaptedMovies;

public:
    Comic(string publisher, int year, string ageLimit, string author, string translator, vector<string> adaptedMovies)
        : Fiction(publisher, year, ageLimit, author, translator), adaptedMovies(adaptedMovies) {}

    void display() {
        Fiction::display();
        cout << "Adapted Movies: ";
        for (const string& movie : adaptedMovies) {
            cout << movie << ", ";
        }
        cout << endl;
    }
};

int main() {
    // Tạo các đối tượng và hiển thị thông tin
    Textbook textbook("Education Publisher", 2020, "Mathematics", {"School A", "School B"});
    textbook.display();

    ExerciseBook exerciseBook("Education Publisher", 2021, "Physics", "Advanced");
    exerciseBook.display();

    RomanceNovel romanceNovel("Fiction Publisher", 2019, "16+", "Author X", "Translator Y", 20);
    romanceNovel.display();

    Comic comic("Comic Publisher", 2018, "12+", "Author Z", "Translator W", {"Movie 1", "Movie 2"});
    comic.display();

    return 0;
}