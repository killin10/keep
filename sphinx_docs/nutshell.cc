/**
 * With a little bit of a elaboration, should you feel it necessary.
 *
 * yiu see.
 *
 * @date Thu Aug 24 11:05:04 2017
 * @author Shi Wei (shiwei2012@gmail.com)
 */

class Nutshell
{
public:

  /**
   * Our tool set
   *
   * The various tools we can opt to use to crack this particular nut
   */
    enum Tool
    {
        kHammer = 0,          //!< What? It does the job
        kNutCrackers,         //!< Boring
        kNinjaThrowingStars   //!< Stealthy
    };

    /**
     * Nutshell constructor
     *
     * @see ~Nutshell()
     */
    Nutshell();

    /**
     * Nutshell destructor
     */
    ~Nutshell();

    /**
     * Crack that shell with specified tool
     *
     * @param tool [in] the tool with which to crack the nut
     */
    void crack( Tool tool );

    /**
     * @return  Whether or not the nut is cracked
     */
    bool isCracked();

private:

    /**
     * Our cracked state
     */
    bool m_isCracked;

};

