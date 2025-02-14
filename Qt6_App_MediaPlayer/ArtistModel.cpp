#include "ArtistModel.h"

ArtistModel::ArtistModel(QObject *parent) : QAbstractListModel(parent)
{
    // Construct artists (optional)
    artists.append({"Coldplay", 1});
    artists.append({"OneRepublic", 2});
}

int ArtistModel::rowCount(const QModelIndex &parent) const
{
    return parent.isValid()? 0 : artists.size(); // why parent.isValid()? 0
}

QVariant ArtistModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || index.row() >= artists.size())
        return QVariant();

    const Artist &artist = artists[index.row()];
    if (role == NameRole) return artist.name;
    if (role == SongCountRole) return artist.songCount;

    return QVariant();
}

QHash<int, QByteArray> ArtistModel::roleNames() const
{
    return {{NameRole, "name"}, {SongCountRole, "songCount"}};
}

// Add data (exposed to QML)
void ArtistModel::addArtist(QString name, int songCount)
{
    beginInsertRows(QModelIndex(), artists.size(), artists.size());
    artists.append( {name, songCount});
    endInsertRows();
}
