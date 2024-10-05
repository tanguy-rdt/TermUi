#ifndef ABSTRACT_LINE_H
#define ABSTRACT_LINE_H

class AbstractLine {
    public:
        enum class LineType {
            TITLE,
            CATEGORY,
            SUBCATEGORY,
            SELECTABLE,
            MENU,
        };

        enum class LineInteraction {
            UNFOCUSABLE = 0,
            FOCUSABLE   = 1 << 0,
            SELECTABLE  = 1 << 1,
        };

        virtual ~AbstractLine() {}

        virtual void highlight(bool enable) = 0;
        virtual void toggle() = 0;
        virtual void draw() = 0;

        bool hasInteraction(LineInteraction interaction) {
            return _interaction & static_cast<int>(interaction);
        }

        void addInteraction(LineInteraction interaction) {
            _interaction |= static_cast<int>(interaction);
        }

        int getInteraction() {
            return _interaction;
        }

    private:
        int _interaction = 0;
};

#endif // ABSTRACT_LINE_H