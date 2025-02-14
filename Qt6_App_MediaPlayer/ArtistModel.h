#ifndef ARTISTMODEL_H
#define ARTISTMODEL_H

#include <QAbstractListModel>

struct Artist {
    QString name;
    int songCount;
};

class ArtistModel : public QAbstractListModel {
    Q_OBJECT

public:
    explicit ArtistModel(QObject *parent = nullptr);

    enum Roles {
        NameRole = Qt::UserRole + 1,
        SongCountRole
    };

    // QAbstractItemModel interface
    virtual int rowCount(const QModelIndex &parent) const override;
    virtual QVariant data(const QModelIndex &index, int role) const override;
    virtual QHash<int, QByteArray> roleNames() const override;

    Q_INVOKABLE void addArtist(QString name, int songCount);

private:
    QList<Artist> artists;
};

#endif // ARTISTMODEL_H
