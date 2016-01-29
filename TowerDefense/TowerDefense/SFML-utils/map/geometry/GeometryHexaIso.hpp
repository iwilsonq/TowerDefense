#ifndef SFUTILS_GEOMETRY_HEXAISO_HPP
#define SFUTILS_GEOMETRY_HEXAISO_HPP

#include <SFML-utils/map/geometry/Geometry.hpp>

namespace sfutils
{
    namespace geometry
    {
        class GeometryHexaIso : public GeometryHexaBase
        {
            public:
                GeometryHexaIso(float scale);
                virtual ~GeometryHexaIso();

                virtual sf::Vector2f mapCoordsToPixel(const sf::Vector2i& coord) const override;
                virtual sf::Vector2i mapPixelToCoords(const sf::Vector2f& pos) const override;
        };
    }
}
#endif
