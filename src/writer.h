#ifndef wotreplay_writer_h
#define wotreplay_writer_h

#include "game.h"

#include <iosfwd>

namespace wotreplay {
    /**
     * writer_t describes the interfaces for all classes with the ability to create an
     * output from game_t objects.
     */
    class writer_t {
    public:
        /**
         * Initializes the object.
         * @param map The name of the map.
         * @param mode The game mode.
         */
        virtual void init(const std::string &map, const std::string &mode) = 0;
        /**
         * The last step in creating an image. It is called after all packets have
         * been processed. It is illegal to call void update(const packet_t &packet)
         * or void writer_t::finish() again after this method. The only valid methods
         * are void writer_t::reset() and void image_t::write_image(const std::string &path);
         */
        virtual void finish() = 0;
        /**
         * Empties modifications made by writer_t::update(const game_t &game). After calling this method,
         * the object should find itself in the state after calling init(map, mode)
         */
        virtual void clear() = 0;
        /**
         * Resets the writer to an empty state.
         */
        virtual void reset()  = 0;
        /**
         * Updates the writer with the information of the game.
         * @param game The packet containing the information to be processed.
         */
        virtual void update(const game_t &game) = 0;
        /**
         * Write a game object to an output stream.
         * @param os Outputstream to write the game to.
         */
        virtual void write(std::ostream& os) = 0;
        /**
         * @return Returns if the object is initialized.
         */
        virtual bool is_initialized() const = 0;

        virtual ~writer_t() = default;
    };
}

#endif /* defined(wotreplay_writer_h) */
