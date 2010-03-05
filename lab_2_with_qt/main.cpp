#include <QtCore/QCoreApplication>
#include <QtDebug>
#include <QRegExp>
#include <QString>
#include <QFile>
#include <QIODevice>

QString read_file(char * filename){
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly|QIODevice::Text)){
        return NULL;
    }
    QString s(file.readAll());
    return s;
}

QString str_clean(QString str){
    // RegExp - forever!
    char * replace_word = "Vau!!!";
    //str.remove(QRegExp("[^\\w\ \,\.]"));
    //str.replace(QRegExp("[\\s]{2,}"),"\\s");
    str = str.simplified();
    str.replace(QRegExp(" (,|\\.)"),"\\1 ");
    str.replace(QRegExp("(,|\\.)([a-z])"),"\\1 \\2");
    str.replace(QRegExp("[\\w]{10,}\."), replace_word);
    return str;
}

void pretty_print(QString str, int width){
    QString str_v;
    int last_pos = 0;
    int max_pos = str.size();
    int start = 0;
    int offset = 0;
    int end = 0;
    int line_width;
    while (true){
        start = last_pos;
        line_width = width;
        end = start+line_width;
        if (!(last_pos+line_width >= max_pos)) {
            offset = str.lastIndexOf(" ", end);
            if (offset != -1){
                line_width = line_width - (end - offset);
            }
        }
        str_v.push_back(str.mid(start, line_width));
        str_v.push_back("\n");
        last_pos = start+line_width;
        if (last_pos >= max_pos){
            break;
        }

    }
    qDebug() << str_v;
}
int main(int argc, char *argv[])
{
    QString s = read_file("input.txt");
    qDebug() << s;
    s = str_clean(s);
    qDebug() << s;
    pretty_print(s, 40);
}
